
#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

public:
    Complex(int i = 0, int j = 0) { // constructor
        real = i;
        img = j;
    }
    Complex(){
        real =0;
        img =0;
    }

    void setReal(int realData){
        if (real >0){
           real = realData;
        }
    }
    int getReal(){
        return real;
    }
    void setImg (int imgData){
        if (img >0){
            img = imgData;
        }
    }
    int getImg(){
        return img;
    }

    void display (){
        //if real + / - i will print it without change
        //if img - don't change , if + i will add + to the output ,if 0 not print 0
        //real =0
         if (real == 0 && img ==0){
            cout<<"no data"<<endl;

        }
        //there data in real
        else {
            //img !=0
            if (real !=0){
            cout<<real<<endl;
            }
            if (img >0){
                cout<<real<<" + "<<img<<"i"<<endl;
            }
            else if (img <0) {
                cout<<real<<img<<"i"<<endl;
            }
        }
    }
    void setComplex(int real, int img){
    this->real = real;
    this->img = img;
    }
    Complex add(Complex c){
        return Complex(real + c.real, img + c.img);
    }
    Complex sub(Complex c){
         return Complex(real - c.real, img - c.img);
    }
    Complex operator+(Complex c1){
        return Complex(this->real +c1.real , this->img +c1.img);
    }
    Complex operator+ (int x){
        return Complex(this->real +x , this->img);
    }
    Complex operator-(Complex c) {
        return Complex(this->real - c.real, this->img - c.img);
    }
    Complex operator-(int x){
        return Complex(this->real - x , this->img);
    }

    Complex operator+=(Complex c1){
        return Complex(this->real +=c1.real , this->img +=c1.img);
    }
    bool operator==(Complex c1){
        return (this->real ==c1.real && this->img ==c1.img);
    }

    Complex operator++() { // prefix
        this->real++;
        this->img++;
        return *this;
    }

    Complex operator--() { // prefix
        this->real--;
        this->img--;
        return *this;
    }

    Complex operator++(int x) { // postfix
        Complex c = *this;
        this->real++;
        this->img++;
        return c;
    }
    Complex operator--(int x) { // postfix
        Complex c = *this;
        this->real--;
        this->img--;
        return c;
    }

    ~Complex(){ //destructor
      cout<<"object destroyed"<<endl;  //called many times caused by the temporary objects created during operations.
      cout<<"------------------"<<endl;
    }

};
//standalone functions c=5+c1;
Complex operator+(int x, Complex c) {
    Complex result(c.getReal() + x, c.getImg());
    return result;
}

Complex operator-(int x, Complex c) {
    Complex result(c.getReal() - x, c.getImg());
    return result;
}
int main() {
    Complex c1(10, 5);
    c1.display(); //10 + 5i

    Complex c3(0, 0);
    c3.display(); //0 + 0i

    Complex c2(3, -4);
    c2.display();  //3 - 4i

    Complex sum = c1.add(c2);
    cout << "Sum: ";
    sum.display();  // 13 + 1i

    Complex difference = c1.sub(c2);
    cout << "Difference: ";
    difference.display();  //7 - 2i

    Complex c4(0, 0);
    c4.setComplex(7, -2);
    cout << "Using setComplex Function): "<<endl;
    c4.display();

    Complex c5 = c1 + c2;
    cout << "Result of c1 + c2: ";
    c5.display();  //13 + 1i

    c5 = c1++;
    cout << "After postfix increment (c1): ";
    c5.display();  //11 + 6i

    c5 = ++c1;
    cout << "After prefix increment (c1): ";
    c5.display();  //12 + 7i

    Complex c6 = c3 - c4;
    cout << "Result of c3 - c4: ";
    c6.display();  //-7 + 2i

    c6 = c4--;
    cout << "After postfix decrement (c4): ";
    c6.display();  //6 - 3i

    c6 = --c4;
    cout << "After prefix decrement (c4): ";
    c6.display();  //5 - 4i

    Complex c7 = c1 + 5;
    cout << "Result of c1 + 5: ";
    c7.display();  //15 + 7i

    c7 = c4 - 3;
    cout << "Result of c4 - 3: ";
    c7.display();   //4 - 2i

    Complex c8 =5+c2;
    cout << "Result of 5 + c2: ";
    c8.display();  //8 - 4i

    c8 = 3-c3;
    cout << "Result of 3 - c3: ";
    c8.display(); //3 + 0i

     c1 += c2;  // c1 = c1 + c2
    cout << "c1 += c2: ";
    c1.display(); //13 + 1i

     if (c3 == c4) {
        cout << "c3 == c4: They are equal" << endl;
    } else {
        cout << "c3 == c4: They are not equal" << endl;
    }
    return 0;
}
