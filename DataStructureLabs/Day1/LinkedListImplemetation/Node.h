#ifndef NODE_
#define NODE_

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;
    
    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    ~Node() {}
};

#endif // NODE_
