#include <iostream>

using namespace std;

int main()#include <iostream>

using namespace std;
class Stack {
private:
    int top;
    int size;
    static int count;   //count objects number
    int * items;
public:
    Stack (int size){
        this->size = size;
        top = -1;
        items = new int [size];
        count++;  //increment object counter
    }
    int push (int data){
        if (top == size -1){ //not empty
            return 0;
        }
        top++;
        items[top] = data;
        return 1;
    }
    int pop (int *dataMain){
        if (top == -1){ //empty
            return 0;
        }
        int data=items[top];
        top--;
        *dataMain=data;
        return 1;
    }

    void display (){
        int dis =top;
        if (dis == -1){
            cout<<"Stack is empty \n";
            return;
        }
        for(int i=dis; i>=0; i--){
            cout << items[i] << " "<<endl;
        }


    }
    ~Stack(){  //deconstuctor
         delete[] items;
    }
    static int getCount() {
        return count;
    }
};
int Stack::count = 0;
int main()
{
    int dataMain;
    Stack stack(5);
    stack.push(90)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack.push(30)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack.push(20)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack.push(70)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack.push(50)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack.push(10)?cout<<"Success Push \n" : cout<<"Failure push \n";

    stack.display();

    stack.pop(&dataMain)?cout<<"Success pop data = " <<dataMain<<"\n" : cout<<"Failure pop \n";
    stack.pop(&dataMain)?cout<<"Success pop data = " <<dataMain<<"\n" : cout<<"Failure pop \n";
    stack.pop(&dataMain)?cout<<"Success pop data = " <<dataMain<<"\n" : cout<<"Failure pop \n";
    stack.pop(&dataMain)?cout<<"Success pop data = " <<dataMain<<"\n" : cout<<"Failure pop \n";
    stack.pop(&dataMain)?cout<<"Success pop data = " <<dataMain<<"\n" : cout<<"Failure pop \n";
    stack.pop(&dataMain)?cout<<"Success pop data = " <<dataMain<<"\n" : cout<<"Failure pop \n";

    stack.display();

    // Check the number of stack objects
    cout << "Number of active Stack objects: " << Stack::getCount() << endl;
    return 0;
}

    cout << "Hello world!" << endl;
    return 0;
}
