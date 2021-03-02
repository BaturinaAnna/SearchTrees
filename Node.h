#pragma once


class Node {
private:
    int key;
    Node* left;
    Node* right;
    int height;
public:
    Node(int key);
    int getKey();
    Node* getLeft();
    Node* getRight();
    int getHeight();
    void setKey(int);
    void setLeft(Node*);
    void setRight(Node*);
    void setHeight(int);
};
