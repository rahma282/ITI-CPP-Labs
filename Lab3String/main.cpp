#include <iostream>
#define TERMINATOR '\0'
using namespace std;
class String
{
private:
    char *ptr;
    int size;
    int capacity;
    //private functions
    void resizeArrayOfString(int newCapacity)   //resize the array dynamically when needed
    {
        char *newPtr = new char [newCapacity];  //newptr point to new array
        //put values of old array into new array
        for (int i=0; i<size; ++i)
        {
            newPtr[i] = ptr[i];
        }
        newPtr[size]= TERMINATOR;
        delete []ptr; //delete old array
        ptr = newPtr;
        capacity = newCapacity;
    }

    int stringLength(char str[])
    {
        int length = 0;

        while (str[length] != TERMINATOR)
        {
            length++;
        }
        return length;
    }

public:
    //constuctors
    String()
    {
        size = 0;
        capacity = 1;
        ptr = new char[capacity];
        ptr[0] = TERMINATOR;
    }
    String (char *s)
    {
        if (s == nullptr)
        {
            size = 0;
            capacity = 1;
            ptr = new char[capacity];
            ptr[0] = TERMINATOR;
        }
        else
        {
            size= stringLength(s);
            capacity = size +1 ;//+terminator
            ptr = new char[capacity];
            for (int i=0; i<size; i++)
            {
                ptr[i] = s[i];
            }
            ptr[size] =TERMINATOR;
        }
    }
    String(String& s)    //copy constructor
    {
        size = s.size;
        capacity = s.capacity;
        ptr = new char[capacity];
        for (int i = 0; i < size; ++i)
        {
            ptr[i] = s.ptr[i];
        }
        ptr[size] = TERMINATOR;
    }
    ~String()
    {
        delete []ptr;
    }

    //public functions
    int getLength()  //return the string size
    {
        return size;
    }
    void print()   //print string
    {
        cout <<ptr<< endl;
    }

    void StringConcat(char *str) {
        int appendSize = stringLength(str);
        int newSize = size + appendSize;
        if (newSize >= capacity) {
            resizeArrayOfString(newSize + 1);  // +1 for the null terminator
        }

        for (int i = 0; i < appendSize; ++i) {
            ptr[size + i] = str[i];
        }

        size = newSize;
        ptr[size] = TERMINATOR;  // Null-terminate the new string
}


    void toLower()
    {
        for (int i = 0; i < size; ++i)
        {
            if (ptr[i] >= 'A' && ptr[i] <= 'Z')
            {
                ptr[i] += 32;
            }
        }
    }
    void toUpper()
    {
        for (int i = 0; i < size; ++i)
        {
            if (ptr[i] >= 'a' && ptr[i] <= 'z')
            {
                ptr[i] -= 32;
            }
        }
    }
    void copyString(char *str)
    {
        size = stringLength(str);
        if (size >= capacity)
        {
            resizeArrayOfString(size + 1);
        }

        for (int i = 0; i < size; ++i)
        {
            ptr[i] = str[i];
        }

        ptr[size] = TERMINATOR;
    }
    int strCompare(String &s)
    {
        if (size != s.size)
        {
            return size < s.size ? -1 : 1;
        }

        for (int i = 0; i < size; ++i)
        {
            if (ptr[i] != s.ptr[i])
            {
                return ptr[i] < s.ptr[i] ? -1 : 1;
            }
        }
        return 0;  // strings are equal
    }

    // comparison operators
    bool operator==(String &s)
    {
        return strCompare(s) == 0;
    }

    bool operator!=(String &s)
    {
        return strCompare(s) != 0;
    }

    bool operator<(String &s)
    {
        return strCompare(s) < 0;
    }

    bool operator<=(String &s)
    {
        return strCompare(s) <= 0;
    }

    bool operator>(String &s)
    {
        return strCompare(s) > 0;
    }

    bool operator>=(String &s)
    {
        return strCompare(s) >= 0;
    }
};
void printline(){
cout<<"--------------------------"<<endl;
}
int main()
{
    String str1("Hello");
    str1.print();
    printline();

    String str2("Hello");
    cout << "Comparison result using ==: " << (str1 == str2 ? "Equal" : "Not equal") << endl;

    str1.StringConcat(" World");
    str1.print();
    printline();

    str1.toUpper();
    str1.print();
    printline();

    str1.toLower();
    str1.print();
    printline();

    cout << "Comparison result using ==: " << (str1 == str2 ? "Equal" : "Not equal") << endl;
    cout << "Comparison result using strCompare: " << str1.strCompare(str2) << endl;

    String str3("hello");
    str3.StringConcat(" yyy");
    str3.print();
    printline();

    String str4("hi");
    str4.copyString("okay");
    str4.print();
    printline();

    cout << "Length of str1: " << str1.getLength() << endl;
    cout << "Length of str2: " << str2.getLength() << endl;
    cout << "Length of str3: " << str3.getLength() << endl;
    cout << "Length of str4: " << str4.getLength() << endl;
    printline();


    return 0;

}

/*
the main constructors are:
1-default -- > builds an empty string  ---> string();
2-Conversion constructor -- > converts a C-string into a string ---> string(const char* s);
3-Copy constructor --> makes a new string by copying a string ---> string(const string& s);

a.calls one of the string constructors as each of the variables/objects s1 through s4 are defined.
The string member functions size and length are synonyms - they are different names for the same operation,
which is getting the number of characters currently stored in a string object.
The string member function capacity gets the number of characters the string can store before it must grow.

b.The output from program (a) demonstrates an interesting behavior of many string implementations:
the capacity of empty or short string objects is greater than their size.
We can speculate that the string implementors chose this behavior to speed up the string-growing process

c.C++ implements string objects as arrays of characters.Furthermore, Many C++ compilers create new string objects with a capacity
greater than the number of characters stored. The total number of elements in the array is the string's capacity.
The blue characters are used or filled and correspond to the size or length of the string. The empty white boxes are unused -
they contain whatever random bit pattern was in memory before the program created the string. Nevertheless, size ≤ capacity.

string Operators:
= -->Assignment --> Converts a C-string to a string  s1 = s2;   s = "Hello, World!"
+ --> Concatenation  s = s1 + s2;
+= --> Concatenation with assignment s += s2
== --> Equality     if (s1 == s2) . . .
!= --> Inequality   if (s1 != s2) . . .
<, <=, >, >= --> relations  if (s1 < s2) . . .
[] and at() --> Character access       char c = s1[i];

functions:
private:
stringLength: A utility function to determine the length of a C-string.
Dynamic Resizing: The resize function ensures that the internal array grows as needed.
public
Member Functions: These handle string manipulation like appending, converting case, copying, and comparing.
Operator Overloading: Comparison operators are overloaded for easy string comparison.
Character Access: Both operator[] and at() allow for safe character access, with at() providing bounds checking.
*/
