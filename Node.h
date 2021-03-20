#pragma once


class Node {
protected:
    int key;
    Node* left;
    Node* right;
public:
    Node(int);
    int getKey();
    Node* getLeft();
    Node* getRight();
    void setKey(int);
    void setLeft(Node*);
    void setRight(Node*);
    virtual ~Node() {};
};
