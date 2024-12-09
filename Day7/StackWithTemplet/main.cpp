#include <iostream>
using namespace std;
template <class T>
class Stack {
private:
    int top;
    int size;
    T * items;
public:
    Stack(int size) {
    this->size = size;
    top = -1;
    items = new T[size]; 
}
    T push (T data){
        if (top == size -1){ //not empty
            return 0;
        }
        top++;
        items[top] = data;
        return 1;
    }
    T pop (T *dataMain){
        if (top == -1){ //empty
            return 0;
        }
        T data=items[top];
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
};
int main()
{
    int dataMain;
    Stack <int> stack (5);
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

    double dataMain1;
    Stack <double> stack2 (5);
    stack2.push(90.5)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack2.push(30.5)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack2.push(20.5)?cout<<"Success Push \n" : cout<<"Failure push \n";
    stack2.display();

    stack2.pop(&dataMain1)?cout<<"Success pop data = " <<dataMain1<<"\n" : cout<<"Failure pop \n";
    stack2.pop(&dataMain1)?cout<<"Success pop data = " <<dataMain1<<"\n" : cout<<"Failure pop \n";
    stack2.pop(&dataMain1)?cout<<"Success pop data = " <<dataMain1<<"\n" : cout<<"Failure pop \n";

    stack2.display();

    return 0;
}
