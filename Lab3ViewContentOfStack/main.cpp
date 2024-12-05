#include <iostream>
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
        cout << "Constructor called. Stack size: " << size << ", Object count: " << count << endl;

    }
     // Copy Constructor
//    Stack( Stack& s) {
//         create a deep copy of the s stack
//        this->size = s.size;
//        this->top = s.top;
//        this->items = new int[this->size];
//
//         copy all elements from the s stack  deep copy
//        for (int i = 0; i <= s.top; i++) {
//            this->items[i] = s.items[i];
//        }
//
//        count++;
//        cout << "Copy constructor called. Object count: " << count << endl;
//    }
    int push (int data){
        if (top == size -1){ //stack is full
            return 0;
        }
        top++;
        items[top] = data;
        return 1;
    }
    int pop (int *dataMain){
        if (top == -1){ //stack is empty
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
    Stack& operator=(Stack &s) {
    if (this == &s) return *this;  // self-assignment check

    delete[] this->items;  // Clean up old memory
    this->size = s.size;
    this->top = s.top;
    this->items = new int[this->size];

    // Copy all elements from the stack (deep copy)
    for (int i = 0; i <= s.top; i++) {
        this->items[i] = s.items[i];
    }

    cout << "Assignment operator called. Object count: " << count << endl;
    return *this;
}

    ~Stack(){  //deconstuctor
         delete[] items;
         count--;
          cout << "Destructor called. Object count: " << count << endl;
    }
    static int getCount() {
        return count;
    }
};

/*viewContent function once call by value and without copy constructor. . (to see
   the extra destructor call).*/
void viewContentByValue(Stack s) {
    int dataMain;
    cout << "view content by value without copy constructor: "<<endl;
    // pop until stack is empty
    while (s.pop(&dataMain)) {
    cout << "Popped value: " << dataMain << endl;
    }
}/*
 viewContent function once call by value and with copy constructor.
void viewContentByValueWithCopyConstructor(Stack s){
     int dataMain;
    cout << "view content by value with copy constructor(DeepCopy): "<<endl;
    while (s.pop(&dataMain)) {
        cout << "Popped value: " << dataMain << endl;
    }
 }

 //viewContent function once call by reference.
 void viewContentByRefernce(Stack &s){
     int dataMain;
     cout << "view content by refernce: "<<endl;
    while (s.pop(&dataMain)) {
        cout << "Popped value: " << dataMain << endl;
    }
 }
 */
 void print(){
 cout<<"-------------------------"<<endl;
 }
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
    print();

    //pop 50 70 20 30 90
    Stack stack2(3);
    stack2 = stack; // using the assignment operator

    cout << "Contents of stack2 after assignment: " << endl;
    stack2.display();
    print();
    cout << "Number of active Stack objects: " << Stack::getCount() << endl;


    viewContentByValue(stack);
    viewContentByValue(stack);

    /*
    viewContentByValueWithCopyConstructor(stack);
    viewContentByValueWithCopyConstructor(stack);

    viewContentByRefernce(stack);
    viewContentByRefernce(stack);
    */
    return 0;
}
