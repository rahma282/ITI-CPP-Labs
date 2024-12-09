#include <iostream>
#include <cstring>
using namespace std;
class DynamicList {
private:
    enum Types {
        Type_Int,
        Type_Double,
        Type_CString
    };
    void ** data;             //array of pointers to void (generic data type) .. it can point to any data type allowing you to store pointers to data of various types (like int, double, char*)
    int * types;             //array of int pointer hold types tages to keep track of the types of data stored in the array of data 
    size_t size;            //size_t is an unsigned integer types that is commonly used to represent sizes or indices in arrays.
    size_t capacity;       //using size_t ensures that capacity can represent large sizes in a safe, non-negative way.

    void resize(){
        size_t newCapacity = capacity * 2; //initial capacity = 2.  after each resize: 2 → 4 → 8 → 16
        void ** newData = new void *[newCapacity];
        int * newTypes = new int [newCapacity];
        for (int i =0; i< size; i++){
            newData[i] = data[i];   //copy data from the old array to the new one 
            newTypes [i] = types[i];
        }
        delete [] data;
        delete [] types;   //delete old array
        data = newData;   //move data back to the old resized array
        types = newTypes;
        capacity = newCapacity;
    }
public:
        DynamicList(){
            // initialize data with space for 2 void pointers
            data = new void*[2];
            // initialize types array with space for 2 integers to store types info for each element in the dynamic list
            types = new int [2]; 
            /*
            Each element in types corresponds to an element in the data array.
            if data[i] stores a pointer to an int, types[i] will store TYPE_INT.
            if data[i] stores a pointer to a double, types[i] will store TYPE_DOUBLE, ...*/
            capacity =2;
            size=0;
        }
        void push (int value){
            if (size == capacity){ //list is full
                resize();
            }
            data[size] = new int (value);  //pass the value, datatype to the array of data 
            types[size] = Type_Int; 
            size++;
        }
        void push (double value){
            if (size == capacity){ 
                resize();
            }
            data[size] = new double (value);  
            types[size] = Type_Double;
            size++;
        }
        void push (char * value){
            if (size == capacity){ 
                resize();
            }
            size_t len = strlen(value) + 1; // +1 for null terminator
            char* charArray = new char[len];  
            strcpy(charArray, value); // Copy the input string
            data[size] = charArray;
            types[size] = Type_CString;
            size++;
        }

        int getInt(size_t index){
            if (index >=size || types[index] != Type_Int){
                throw runtime_error("Type mismatch or index out of range");
            }
            return *static_cast<int*>(data[index]);//performs cast, which tells the compiler to treat data[index] as a pointer to int and return int value in spacific index
        }
        double getDouble(size_t index){
            if (index >=size || types[index] != Type_Double){
                throw runtime_error("Type mismatch or index out of range");
            }
             return *static_cast<double*>(data[index]); // i dereferencing the pointer to get the actual value it points to
        }
        const char* getCString(size_t index) const {
        if (index >= size || types[index] != Type_CString) {
            throw runtime_error("Type mismatch or index out of range");
        }
        return static_cast<char*>(data[index]); //i don't need a * before the static_cast<char*> is that you're casting the pointer itself char*
    }
    void pop (){
        if (size ==0){
            throw runtime_error("List is empty ... can't pop");
        }
         if (types[size - 1] == Type_CString) {
            delete[] static_cast<char*>(data[size - 1]); 
        } else {
            delete data[size - 1];
        }
        size--;
    }
    void display(){
        for (size_t i = 0; i < size; ++i) {
            switch (types[i]) {
                case Type_Int:
                    cout << "Item " << i+1 << " is an int: " << getInt(i) << endl;
                    break;
                case Type_Double:
                    cout << "Item " << i+1 << " is a double: " << getDouble(i) << endl;
                    break;
                case Type_CString:
                    cout << "Item " << i+1 << " is a string: " << getCString(i) << endl;
                    break;
            }
        }
    }

    ~DynamicList() {
        for (size_t i = 0; i < size; ++i) {
            if (types[i] == Type_CString) {
                delete[] static_cast<char*>(data[i]); // deallocate char array
            } else {
                delete data[i]; // deallocate int or double array
            }
        }
        delete[] data;
        delete[] types;
    }
        

};

int main() {
    DynamicList list;
    list.push(42);
    list.push(3.14);
    list.push("Hello C++ .. it's me");
    list.push("i love java ..");

    cout << "Before popping:\n";
    list.display();

    // Remove the last item
    list.pop(); // i love java
    list.pop(); //hello c++ ...
   
    cout << "\nAfter popping:\n";
    list.display();

    return 0;
}

