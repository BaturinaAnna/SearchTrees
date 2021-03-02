#include "AVLTree.h"

AVLTree::AVLTree(std::set<int> tree) {
    set<int>::iterator setIt = tree.begin();
    Node* root = new Node(*setIt);
    setIt++;
    for (int i = 1; i < tree.size(); i++) {
        root = insert_element(root, *setIt);
        setIt++;
    }
    this->root = root;
}
 
Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->getLeft();
    Node* T2 = x->getRight();
 
    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(max((y->getLeft())->getHeight(), (y->getRight())->getHeight()) + 1);
    x->setHeight(max((x->getLeft())->getHeight(), (x->getRight())->getHeight()) + 1);

    root = x;
    return x;
}


Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->getRight();
    Node* T2 = y->getLeft();
 
    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(max((x->getLeft())->getHeight(), (x->getRight())->getHeight()) + 1);
    y->setHeight(max((y->getLeft())->getHeight(), (y->getRight())->getHeight()) + 1);

    root = y;
    return y;
}


int AVLTree::getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return (N->getLeft())->getHeight() - (N->getRight())->getHeight();
}


Node* AVLTree::insert_element(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->getKey())
        root->setLeft(insert_element(root->getLeft(), key));
    else if (key > root->getKey())
        root->setRight(insert_element(root->getRight(), key));
    else
        return root;

    root->setHeight(1 + max((root->getLeft())->getHeight(), (root->getRight())->getHeight()));

    int balance = getBalance(root);

    // Left Left Case  
    if (balance > 1 && key < root->getLeft()->getKey())
        return rightRotate(root);

    // Right Right Case  
    if (balance < -1 && key > root->getRight()->getKey())
        return leftRotate(root);

    // Left Right Case  
    if (balance > 1 && key > root->getLeft()->getKey()) {
        root->setLeft(leftRotate(root->getLeft()));
        return rightRotate(root);
    }

    // Right Left Case  
    if (balance < -1 && key < root->getRight()->getKey()) {
        root->setRight(rightRotate(root->getRight()));
        return leftRotate(root);
    }

    this->root = root;
    return root;
}


Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;

    while (current->getLeft() != nullptr)
        current = current->getLeft();

    return current;
}


Node* AVLTree::delete_element(Node* root, int key)
{ 
    if (root == nullptr)
        return root;

    if (key < root->getKey())
        root->setLeft(delete_element(root->getLeft(), key));
 
    else if (key > root->getKey())
        root->setRight(delete_element(root->getRight(), key));
 
    else { 
        if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) {
            Node* temp = root->getLeft() ? root->getLeft() : root->getRight();
  
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;  
            free(temp);
        }
        else { 
            Node* temp = minValueNode(root->getRight());
            root->setKey(temp->getKey());
            root->setRight(delete_element(root->getRight(), temp->getKey()));
            //delete_element(root->getRight(), temp->getKey());
        }
    }

    if (root == nullptr)
        return root;
 
    root->setHeight(1 + max((root->getLeft())->getHeight(), (root->getRight())->getHeight()));

    int balance = getBalance(root);

    // Left Left Case  
    if (balance > 1 && getBalance(root->getLeft()) >= 0)
        return rightRotate(root);

    // Left Right Case  
    if (balance > 1 && getBalance(root->getLeft()) < 0)
    {
        root->setLeft(leftRotate(root->getLeft()));
        return rightRotate(root);
    }

    // Right Right Case  
    if (balance < -1 && getBalance(root->getRight()) <= 0)
        return leftRotate(root);

    // Right Left Case  
    if (balance < -1 && getBalance(root->getRight()) > 0)
    {
        root->setRight(rightRotate(root->getRight()));
        return leftRotate(root);
    }
    return root;
}

bool search(Node* root, int key, bool finded) {
    if (root != nullptr)
    {
        if (root->getKey() == key) {
            finded = true;
        }
        else if (root->getKey() < key) {
            finded = search(root->getRight(), key, finded);
        }
        else {
            finded = search(root->getLeft(), key, finded);
        }       
    }
    return finded;
}

bool AVLTree::search_element(Node* root, int key) {
    bool finded = false;
    return search(root, key, finded);
}

Node* AVLTree::getRoot() {
    return this->root;
}

void AVLTree::print(Node* root) {
    if (root != nullptr) {
        cout << root->getKey() << " ";
        print(root->getLeft());
        print(root->getRight());
    }
}
