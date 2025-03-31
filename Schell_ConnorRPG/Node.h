#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr){ } // TODO: Implement constructor here

    ~Node() {
        delete left;
        delete right;
    }
};

#endif // NODE_H