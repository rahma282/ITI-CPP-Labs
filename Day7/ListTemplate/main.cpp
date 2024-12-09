#include <iostream>
using namespace std;
template <class T>
class List {
private:
    int size;
    T * item;

public:
    List()
    {
        size =0;
       item = NULL;
    }

    void push (T data)
    {
        T * ptr = new T [size+1];
        for (int i=0; i<size; ++i)
        {
            ptr[i] = item[i];
        }
        ptr[size]=data;
        delete []item; //delete old array
        item = ptr;
        size++;
        }


    T pop (T *dataMain){
         if (size == 0) {
            cout << "List is empty. Cannot pop." << endl;
            return -1;
        }
        T data = item[size - 1];
        size--;
        *dataMain = data;
        return 1;
    }

    void display (){
        int dis =size-1;
        if (dis == -1){
            cout<<"List is empty \n";
            return;
        }
        for(int i=dis; i>=0; i--){
            cout << item[i] << " "<<endl;
        }
    }
    int getLength() {
        return size;
    }
    ~List(){  //deconstuctor
         delete[] item;
    }
};
int main()
{
    int dataMain;
    List <int> l;
    l.push(3);
    cout<<"Success Push \n";
    l.push(4);
    cout<<"Success Push \n";
    l.push(6);
    cout<<"Success Push \n";
    l.display();
    cout << "List Length after length: " << l.getLength() << endl;

    l.pop(&dataMain);
    cout<<"Success pop \n";
    l.pop(&dataMain);
    cout<<"Success pop \n";
    l.pop(&dataMain);
    cout<<"Success pop \n";

    l.display();
    cout << "List Length after pops: " << l.getLength() << endl;

    double dataMain1;
    List <double> l1;
    l1.push(3.8);
    cout<<"Success Push \n";
    l1.push(4.7);
    cout<<"Success Push \n";
    l1.display();

    l1.pop(&dataMain1);
    cout<<"Success pop \n";
    l1.pop(&dataMain1);
    cout<<"Success pop \n";
     l1.display();
    return 0;
}
