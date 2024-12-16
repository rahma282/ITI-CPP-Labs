#ifndef LINKEDLIST_
#define LINKEDLIST_
#include "Node.h"
#include <iostream> 
using namespace std;
template <typename T>
class LinkedList
{
    public:
        Node<T>* head;  
        Node<T>* tail;  
        int size;   //trace size of linkedList
        LinkedList(){
            head =nullptr;
            tail =nullptr;
            size =0;
        }
        void add(T data){
        //if it's the first node --> head = tail = newnode;
            Node<T>* newNode = new Node<T>(data);
            size++;
            if (head == nullptr){  // if LinkedList is empty
                head = newNode;
                tail= newNode;
                return;
            }
        /*if it not the first node the there is 3 steps
            1.pointer next of last node point to newNode
                prev|data|next-->newmode
            2.prev pointer of the newnode point to last Node
               last node <--prev|data|next
            3. tail = newnode;
        */
            tail->next = newNode;
            newNode->prev= tail;
            tail = newNode;
            
        }
        void insertAfter(T targetData , T data){
            Node<T>* targetNode = getNodeUsingData(targetData);
            if (targetNode == nullptr) { 
            cout << "Target element not found in the list." << endl;
            return;
            }
            Node<T>* newNode = new Node<T>(data);
            size++;
             // inserting after the target node
            newNode->next = targetNode->next;
            newNode->prev = targetNode;

            if (targetNode->next != nullptr) {  // if not inserting at the tail
                targetNode->next->prev = newNode;
            } else {  // if inserting at the tail
                tail = newNode;
            }

            targetNode->next = newNode;
            return;
        }
        void insertBefore(T targetData, T data){

            Node<T>* targetNode = getNodeUsingData(targetData);
            if (targetNode == nullptr) {
                cout << "Target element not found in the list." << endl;
                return ;
            }

            Node<T>* newNode = new Node<T>(data);
            size++;

            // inserting before the target node
            newNode->next = targetNode;
            newNode->prev = targetNode->prev;

            if (targetNode->prev != nullptr) {  // if not inserting at the head
                targetNode->prev->next = newNode;
            } else {  // if inserting at the head
                head = newNode;
            }

            targetNode->prev = newNode;
            return ;
        }
        bool getDataByIndex(int index, T& outData) {
            if (index < 0 || index >= size) {
                return false; // invalid index
            }

            Node<T>* current = head;
            int currentIndex = 0;

            while (current != nullptr) {
                if (currentIndex == index) {
                    outData = current->data;
                    return true;
                }
                current = current->next;
                currentIndex++;
            }
            return false; 
        }

        void display() {
            Node<T>* current = head;
            if (current == nullptr) {
                cout << "LinkedList is Empty.." << endl;
                return;
            }

            while (current != nullptr) {
                cout << "LinkedList Element: " << "\t" << current->data << endl;
                current = current->next;
            }
            cout << endl;
        }
        bool remove(T data){
            //take the element you wnat to remove
            Node<T>* current = getNodeUsingData(data);

            if (current == nullptr) {
            cout << "Element not found in the list.." << endl;
            return false;
            }
            //if i delete the first node
            if (current == head && current == tail){  //if it's only one node
                head=nullptr;
                tail = nullptr;
            }
            else if (current == head){ //if it's the first node and there are other nodes
                head = head->next;
                head->prev = nullptr;
            }
            //if it's the last node
            else if (current == tail){
            tail = tail->prev;
            tail->next = nullptr;
            }
            else { 
                Node <T>* A = current->prev;
                Node <T>* B = current->next;
                A->next = B;
                B->prev = A;
        }
        delete current;  
        size--;
        return true;
        }
        int getSize(){ 
            return size;
        }
       virtual ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            temp->next = nullptr;  
            delete temp;
        }
        }
        private:
        Node<T>* getNodeUsingData(T data) const {
            Node<T>* current = head;
            while (current != nullptr) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
            }
        return nullptr;
    }
};

#endif // LINKEDLIST_
