#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

public:
     Complex(int i = 0, int j = 0) : real(i), img(j) {}
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
    Complex add(Complex c){
        return Complex(real + c.real, img + c.img);
    }
    Complex sub(Complex c){
         return Complex(real - c.real, img - c.img);
    }

};
int main() {
    Complex c1(10, 5);
    c1.display();

    Complex c3(0, 0);
    c3.display();

    Complex c2(3, -4);
    c2.display();

    Complex sum = c1.add(c2);
    cout << "Sum: ";
    sum.display();

    Complex difference = c1.sub(c2);
    cout << "Difference: ";
    difference.display();

    return 0;
}
