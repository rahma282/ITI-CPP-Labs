#include <iostream>

using namespace std;
class List {
private:
    int size;
    int * item;

public:
    List()
    {
        size =0;
       item = NULL;
    }

    void push (int data)
    {
        int * ptr = new int [size+1];
        for (int i=0; i<size; ++i)
        {
            ptr[i] = item[i];
        }
        ptr[size]=data;
        delete []item; //delete old array
        item = ptr;
        size++;
        }


    int pop (int *dataMain){
         if (size == 0) {
            cout << "List is empty. Cannot pop." << endl;
            return -1;
        }
        int data = item[size - 1];
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
    List l;
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
    return 0;
}
