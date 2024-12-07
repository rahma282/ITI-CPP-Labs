#include <iostream>

using namespace std;
class Base {
protected:
    int a;
    int b;

public:
    Base() {
        cout << "Base constructor called .." << endl;
    }
    Base(int a, int b) {
        this->a = a;
        this->b = b;
        cout << "Base Parametrized Constructor called .." << endl;
    }
    int sub() {
        return a - b;
    }
    ~Base() {
        cout << "Base Destructor called .." << endl;
        cout<<"-----------------------------"<<endl;

    }
};
class Drived : public Base{
    protected :
    int n;
    private:
    int c;

    public:
    Drived() :Base(){
        cout<<"Drived Constructor called .."<<endl;
    }
    Drived(int a , int b ,int n) : Base (a ,b){
        this ->n =n;
        cout<<"Drived Paramtrised Constructor called .."<<endl;
    }
    int getC(){
        return c;
    }

    int sub (){ //override --> change behavoir
        return a-b-n;
    }
    int subBase (){ //override --> extend behavoir
        return Base::sub()-n;
    }
    void display(){
        cout<<"a = "<<a<<" b = "<<b <<" n = "<<n<<endl;
    }
    void display1() {
        cout << "display default" <<endl;
    }
    ~Drived(){
        cout<<"Drived Destructor called .."<<endl;
        cout<<"-----------------------------"<<endl;
    }

};
class SecondDrived : public Drived {
protected:
    int i;

public:
    SecondDrived() : Drived() {
        cout << "SecondDrived Constructor called .." << endl;
    }
    SecondDrived(int a, int b, int n, int i) : Drived(a, b, n) {
        this->i = i;
        cout << "SecondDrived Parametrized Constructor called .." << endl;
    }

    // Override `sub()` - change behavior
    int sub() {
        return a - b - n - i;
    }

    // Override `sub()` - extend behavior
    int subBase() {
        return Drived::sub() - i;
    }

    void display() {
        cout << "a = " << a << " b = " << b << " n = " << n << " i = " << i << endl;
    }


    ~SecondDrived() {
        cout << "SecondDrived Destructor called .." << endl;
        cout<<"-----------------------------"<<endl;
    }
};
void print (){
    cout<<"-------------------------------------------------"<<endl;
}
int main()
{
    Drived e;
    e.display1();
    print();

    Drived d(10,2,3);
    d.display();//10 2 5
    cout<<"Sub ="<<d.sub()<<endl; //10-2-3 = 8-3 = 5
    print();

    Base b(10,2);  //10,2
    Drived d1(10,2,4); //10,2,4
    d1.display();
    cout<<"Sub of Drived ="<<d1.sub()<<endl; //10-2-4 = 8-4 = 4
    print();

    SecondDrived d2(11,2,3,5);
    d2.display();
    cout<<"Sub of SecondDrived ="<<d1.sub()<<endl; //11-2-3-5 = 1
    return 0;
}
