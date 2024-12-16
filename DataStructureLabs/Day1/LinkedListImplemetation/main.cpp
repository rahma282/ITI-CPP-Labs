#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

void print (){
cout<<"-----------------------------------------"<<endl;

}
int main()
{
   LinkedList<int> linkedList;

    linkedList.add(1);
    linkedList.add(2);
    linkedList.add(3);
    linkedList.add(4);


    cout << "--------- linkedList -------:" << endl;
    linkedList.display();

   print();
    cout << "Inserting 6 after 2.." << endl;
    linkedList.insertAfter(2, 6);
    linkedList.display();

    print();
    cout << "Inserting 5 before 2.." << endl;
    linkedList.insertBefore(2, 5);
    linkedList.display();

    print();
    cout << "Removing 30 from the linkedList.." << endl;
    linkedList.remove(30);
    linkedList.display();

    print();
    cout << "Removing 1 from the linkedList.." << endl;
    linkedList.remove(1);
    linkedList.display();

    print();
    cout << "Size of linkedList: " << linkedList.getSize() << endl;

    print();
    int index = 0;
    int data;
    if (linkedList.getDataByIndex(index, data)) {
        cout << "linkedList element at index " << index << ": " << data << endl;
    } else{
        cout << "Invald linkedList index: " << index << endl;
    }


    return 0;
}

