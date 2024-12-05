#include <iostream>
#include <conio.h>
#include <windows.h>
#include <filesystem>
#define UP 72
#define DOWN 80
#define ENTER 13
#define BACKSPACE 8
#define BLUE 1
#define WHITE 7
using namespace std;

class Stack
{
private:
    struct Employee
    {
        int id;
        string name;
        int salary;
    };
    int top;
    int size;
    static int count;   //count objects number
    Employee * employees ;  //pointer to array of employees
public:
    Stack (int size)
    {
        this->size = size;
        top = -1;
        employees= new Employee[size];
        count++;  //increment object counter
    }
    // check if the employee id is numeric and contains no characters
    bool isValidID(const string& idStr)
    {
        for (int i = 0; i < idStr.length(); ++i)
        {
            char c = idStr[i];
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }

    bool isUniqueID(int id)
    {
        for (int i = 0; i <= top; i++)
        {
            if (employees[i].id == id)
            {
                return false;
            }
        }
        return true;
    }

    // check if the employee name is alphabetic and not empty
    bool isValidName(const string& name)
    {
        if (name.empty())
            return false;
        for (int i = 0; i < name.length(); ++i)
        {
            char c = name[i];
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
                return false;
        }
        return true;
    }

    // check if the salary is positive number and numeric
    bool isValidSalary(const string& salaryStr)
    {
        for (int i = 0; i < salaryStr.length(); ++i)
        {
            char c = salaryStr[i];
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }
    int push ()
    {

        if (top == size -1)  //stack is full
        {
            return 0;
        }
        Employee newEmployee;
        string input;

        cout << "Enter Employee ID: ";
        cin >> input;
        while (!isValidID(input) || !isUniqueID(stoi(input)))
        {
            if (!isValidID(input))
            {
                cout << "Invalid ID!, ID must be numeric .. Enter again: ";
            }
            else
            {
                cout << "ID already exists! .. Enter a unique ID: ";
            }
            cin >> input;
        }
        newEmployee.id = stoi(input); //convert string to int

        cout << "Enter Employee Name: ";
        cin.ignore();  // to clear the newline character left by previous input
        getline(cin, newEmployee.name); //to read the full line with spaces
        while (!isValidName(newEmployee.name))
        {
            cout << "Invalid Name!, Name must contain only alphabetic characters .. Enter again: ";
            getline(cin, newEmployee.name);
        }

        cout << "Enter Employee Salary: ";
        cin >> input;
        while (!isValidSalary(input))
        {
            cout << "Invalid Salary!, Salary must be numeric and a positive number .. Enter again: ";
            cin >> input;
        }
        newEmployee.salary = stoi(input);  // convert string to int

        // add the employee to stack
        top++;
        employees[top] = newEmployee;
        cout << "Employee added successfully" << endl;

        return 1;

    }
    int pop (Employee& emp)
    {
        if (top == -1)  //stack is empty
        {
            return 0;
        }
        emp = employees[top];
        top--;
        return 1;
    }

    void display ()
    {
        int dis =top;
        if (dis == -1)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout <<"---- Employee Stack ----"<<endl;
        for(int i=dis; i>=0; i--)
        {
            cout << "ID: " << employees[i].id<< ", Name: " << employees[i].name<< ", Salary: " << employees[i].salary << endl;
        }
    }

    void SetColor(int ForgC)
    {
        WORD wColor;

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        // We use csbi for the wAttributes word.
        if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
        {
            // Mask out all but the background attribute, and add in the foreground color
            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
            SetConsoleTextAttribute(hStdOut, wColor);
        }
    }


    void displayMenu()
    {
        const int menuSize = 4;
        int selected = 0;
        const char* menu[] = { "Push", "Pop", "Display", "Exit" };

        while (true)
        {
            system("cls");
            for (int i = 0; i < menuSize; i++)
            {
                if (i == selected)
                {
                    SetColor(BLUE);
                    cout << menu[i] << endl;
                }
                else
                {
                    SetColor(WHITE);
                    cout << menu[i] << endl;
                }
            }

            // Wait for input
            char ch_in = getch();
            if (ch_in == -32)
            {
                ch_in = getch();
                switch (ch_in)
                {
                case UP:
                    selected = (selected - 1 + menuSize) % menuSize;
                    break;
                case DOWN:
                    selected = (selected + 1) % menuSize;
                    break;
                }
            }
            else if (ch_in == ENTER)
            {
                system("cls");

                switch (selected)
                {
                case 0:  // Push
                    if (push())
                    {
                        SetColor(WHITE);
                        while (true)
                        {
                            cout << "Do you want to add another employee? [y/n]: " << endl;
                            ch_in = getch();

                            if (ch_in == 'y' || ch_in == 'Y')
                            {
                                if (!push())
                                {
                                    cout << "Stack is full.." << endl;
                                    break;
                                }
                            }
                            else if (ch_in == 'n' || ch_in == 'N')
                            {
                                break;
                            }
                            else if (ch_in == BACKSPACE)
                            {
                                cout << endl << "...Back to the menu..." << endl;
                                break;
                            }
                        }
                    }
                    break;

                case 1:  // Pop
                {
                    Employee emp;
                    if (pop(emp))
                    {
                        cout << "Employee popped successfully" << endl;
                        cout << "Employee ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
                    }
                    else
                    {
                        cout << "Failed to pop employee..Stack is empty" << endl;
                    }
                    cout << "Press BACKSPACE to return to the menu." << endl;
                    ch_in = getch();
                    if (ch_in == BACKSPACE)
                    {
                        cout << endl << "...Back to the menu..." << endl;
                    }
                }
                break;

                case 2:  // Display
                    system("cls");
                    SetColor(WHITE);
                    display();
                    cout << "Press BACKSPACE to return to the menu." << endl;
                    ch_in = getch();
                    if (ch_in == BACKSPACE)
                    {
                        cout << endl << "...Back to the menu..." << endl;
                    }
                    break;

                case 3:  // Exit
                    system("cls");
                    SetColor(WHITE);
                    cout << "Do you want to exit? [y/n]: ";
                    ch_in = getch();
                    if (ch_in == 'y' || ch_in == 'Y')
                    {
                        cout << "Exiting program...\n";
                        return; // Exiting the program
                    }
                    else if (ch_in == 'n' || ch_in == 'N')
                    {
                        system("cls"); // Return to the menu
                    }
                    break;
                }
            }

        }
    }

    ~Stack()
    {
        delete[] employees;
        count--; // decrement object count
    }
    static int getCount()
    {
        return count;
    }
};

// static variable count
int Stack::count = 0;

int main()
{
    Stack stack(5);
    stack.displayMenu();
    cout << endl;

    cout << "Number of active Stack objects: " << Stack::getCount() << endl;
    return 0;
}

