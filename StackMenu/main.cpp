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
void SetColor(int ForgC);
using namespace std;

class Stack
{
private:
    struct Employee
    {
        int id;
        string name;
        double salary;
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
    int push ()
    {

        if (top == size -1)  //stack is full
        {
            return 0;
        }
        Employee newEmployee;

        cout << "Enter Employee ID: ";
        cin >> newEmployee.id;

        cout << "Enter Employee Name: ";
        cin.ignore(); // To clear the newline character from the input buffer
        getline(cin, newEmployee.name);

        cout << "Enter Employee Salary: ";
        cin >> newEmployee.salary;

        // add the employee to stack

        top++;
        employees[top] = newEmployee;
        cout << "Employee added successfully!" << endl;

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
        cout << endl<<"---- Employee Stack ----"<<endl;
        for(int i=dis; i>=0; i--)
        {
            cout << "ID: " << employees[i].id<< ", Name: " << employees[i].name<< ", Salary: " << employees[i].salary << endl;
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
            if (ch_in == -32) {
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
                case 0:  // push
                    if (push())
                    {
                        system("cls");
                        SetColor(WHITE);
                        while (true)    // Use `true` for infinite loop (more readable)
                        {
                            cout << "Do you want to add another employee? [y/n]: " << endl;
                            ch_in = getch();
                            if (ch_in == 'y' || ch_in == 'Y')
                            {
                                if (!push()) {
                                    cout<<"Stack is full ..Can't add"<<endl;
                                    break;  // exit if the stack is full
                                }
                            }
                            else if (ch_in == 'n' || ch_in == 'N')
                            {
                                break;  // This break is correctly exiting the while loop
                            }
                        }
                    }
                    break;  // This break is correctly breaking out of the case 0

                case 1: // pop
                    {
                    system("cls");
                    SetColor(WHITE);
                    Employee emp;
                        if (pop(emp))
                        {
                            cout << "Employee popped successfully!" << endl;
                            cout << "Employee ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
                        }
                        else
                            cout << "Failed to pop employee..Stack is empty" << endl;
                    break;
                    }
                case 2:  //display
                    system("cls");
                    SetColor(WHITE);
                    display();
                    break;

                case 3:  // exit
                    system("cls");
                    SetColor(WHITE);
                    cout << "Do you want to exit? [y/n]: ";
                    ch_in = getch();
                    if (ch_in == 'y' || ch_in == 'Y')
                    {
                        cout << "Exiting program...\n";
                        return;
                    }
                     else if (ch_in == 'n' || ch_in == 'N')
                    {
                        system("cls");
                    }
                    break;
                }

                getch(); // Wait for key press

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

// Define static variable count
int Stack::count = 0;

int main()
{
    Stack stack(5);
    stack.displayMenu();
    cout << endl;
    // Check the number of stack objects
    cout << "Number of active Stack objects: " << Stack::getCount() << endl;
    return 0;
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

