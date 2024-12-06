#include <iostream>
using namespace std;

void swapByReference(int &num1, int &num2);
void swapByAddress(int *num1, int *num2);
void swapByValue(int x, int y);

int main(){
 int num1 = 10, num2 = 20;

    cout << "Before swap by address: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapByAddress(&num1, &num2);
    cout << "After swap by address: num1 = " << num1 << ", num2 = " << num2 << endl;

    num1 = 10; num2 = 20;
    cout << "Before swap by reference: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapByReference(num1, num2);
    cout << "After swap by reference: num1 = " << num1 << ", num2 = " << num2 << endl;

    num1 = 10; num2 = 20;
    cout << "Before swap by value: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapByValue(num1, num2);
    cout << "After swap by value: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
void swapByReference(int &num1 ,int  &num2){
   int temp = num1;
    num1 = num2;
    num2 = temp;

}
void swapByAddress(int *num1 ,int * num2){
   if (*num2 != 0) {
    *num1 = *num1 * *num2;
    *num2 = *num1 / *num2;
    *num1 = *num1 / *num2;
    }
    else{
    printf("Error Devision by zero");
    }
}
void swapByValue(int num1 ,int num2){
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}
