#include "AVLTree.h"

AVLTree::AVLTree(set<int> tree) {
    Node* root = nullptr;
    for (auto val : tree) {
        root = insertNode(root, val);
    }
    this->root = root;
}

AVLTree::AVLTree(vector<int> tree) {
    Node* root = nullptr;
    for (auto val : tree) {
        root = insertNode(root, val);
    }
    this->root = root;
}
 
Node* AVLTree::rightRotate(Node* y) {
    NodeAVL* yy = dynamic_cast<NodeAVL*>(y);
    NodeAVL* x = dynamic_cast<NodeAVL*>(yy->getLeft());
    NodeAVL* T2 = dynamic_cast<NodeAVL*>(x->getRight());
 
    x->setRight(yy);
    yy->setLeft(T2);

    if (yy->getLeft() || yy->getRight())
        yy->setHeight(max(dynamic_cast<NodeAVL*>(yy->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(yy->getRight())->getHeight()) + 1);
    else
        yy->setHeight(0);

    if (x->getLeft() || x->getRight())
        x->setHeight(max(dynamic_cast<NodeAVL*>(x->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(x->getRight())->getHeight()) + 1);
    else
        x->setHeight(0);

    root = x;
    return x;
}


Node* AVLTree::leftRotate(Node* x) {
    NodeAVL* xx = dynamic_cast<NodeAVL*>(x);
    NodeAVL* y = dynamic_cast<NodeAVL*>(x->getRight());
    NodeAVL* T2 = dynamic_cast<NodeAVL*>(y->getLeft());
 
    y->setLeft(xx);
    xx->setRight(T2);

    if (xx->getLeft() || xx->getRight())
        xx->setHeight(max(dynamic_cast<NodeAVL*>(xx->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(xx->getRight())->getHeight()) + 1);
    else
        xx->setHeight(0);

    if (y->getLeft() || y->getRight())
        y->setHeight(max(dynamic_cast<NodeAVL*>(y->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(y->getRight())->getHeight()) + 1);
    else
        y->setHeight(0);
    root = y;
    return y;
}


int AVLTree::getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return dynamic_cast<NodeAVL*>(N->getLeft())->getHeight() - dynamic_cast<NodeAVL*>(N->getRight())->getHeight();
}


Node* AVLTree::insertNode(Node* root, int key) {
    if (root == nullptr) {
        Node* r = new NodeAVL(key);
        this->root = r;
        return r;
    }
    
    if (key < root->getKey())
        root->setLeft(insertNode(dynamic_cast<NodeAVL*>(root->getLeft()), key));
    else if (key > root->getKey())
        root->setRight(insertNode(dynamic_cast<NodeAVL*>(root->getRight()), key));
    else
        return root;

    NodeAVL* rroot = dynamic_cast<NodeAVL*>(root);
    rroot->setHeight(1 + max(dynamic_cast<NodeAVL*>(rroot->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(rroot->getRight())->getHeight()));

    int balance = getBalance(rroot);

    // Left Left Case  
    if (balance > 1 && key < rroot->getLeft()->getKey())
        return rightRotate(rroot);

    // Right Right Case  
    if (balance < -1 && key > rroot->getRight()->getKey())
        return leftRotate(rroot);

    // Left Right Case  
    if (balance > 1 && key > rroot->getLeft()->getKey()) {
        rroot->setLeft(leftRotate(dynamic_cast<NodeAVL*>(rroot->getLeft())));
        return rightRotate(rroot);
    }

    // Right Left Case  
    if (balance < -1 && key < rroot->getRight()->getKey()) {
        rroot->setRight(rightRotate(dynamic_cast<NodeAVL*>(rroot->getRight())));
        return leftRotate(rroot);
    }

    this->root = rroot;
    return rroot;
}


Node* AVLTree::minValueNode(Node* node) {
    NodeAVL* current = dynamic_cast<NodeAVL*>(node);

    while (current->getLeft() != nullptr)
        current = dynamic_cast<NodeAVL*>(current->getLeft());

    return current;
}

Node* AVLTree::deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->getKey())
        root->setLeft(deleteNode(dynamic_cast<NodeAVL*>(root->getLeft()), key));
 
    else if (key > root->getKey())
        root->setRight(deleteNode(dynamic_cast<NodeAVL*>(root->getRight()), key));
 
    else { 
        if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) {
            Node* temp = root->getLeft() ? dynamic_cast<NodeAVL*>(root->getLeft()) : dynamic_cast<NodeAVL*>(root->getRight());
  
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
        }
        else { 
            NodeAVL* temp = dynamic_cast<NodeAVL*>(minValueNode((root->getRight())));
            root->setKey(temp->getKey());
            root->setRight(deleteNode(dynamic_cast<NodeAVL*>(root->getRight()), temp->getKey()));
        }
    }

    if (root == nullptr)
        return root;
 
    NodeAVL* rroot = dynamic_cast<NodeAVL*>(root);
    if (rroot->getLeft() || rroot->getRight())
        rroot->setHeight(1 + max(dynamic_cast<NodeAVL*>(rroot->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(rroot->getRight())->getHeight()));
    else
        rroot->setHeight(0);

    int balance = getBalance(rroot);

    // Left Left Case  
    if (balance > 1 && getBalance(dynamic_cast<NodeAVL*>(rroot->getLeft())) >= 0)
        return rightRotate(rroot);

    // Left Right Case  
    if (balance > 1 && getBalance(dynamic_cast<NodeAVL*>(rroot->getLeft())) < 0) {
        rroot->setLeft(leftRotate(dynamic_cast<NodeAVL*>(rroot->getLeft())));
        return rightRotate(rroot);
    }

    // Right Right Case  
    if (balance < -1 && getBalance(dynamic_cast<NodeAVL*>(rroot->getRight())) <= 0)
        return leftRotate(rroot);

    // Right Left Case  
    if (balance < -1 && getBalance(dynamic_cast<NodeAVL*>(rroot->getRight())) > 0) {
        rroot->setRight(rightRotate(dynamic_cast<NodeAVL*>(rroot->getRight())));
        return leftRotate(rroot);
    }
    this->root = rroot;
    return rroot;
}

bool search(Node* root, int key, bool found) {
    if (root != nullptr)
    {
        if (root->getKey() == key) {
            found = true;
        }
        else if (root->getKey() < key) {
            found = search(root->getRight(), key, found);
        }
        else {
            found = search(root->getLeft(), key, found);
        }       
    }
    return found;
}

bool AVLTree::searchNode(Node* root, int key) {
    bool found = false;
    return search(root, key, found);
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

void AVLTree::toSet(Node* root, set<int>& result) {
    if (root != nullptr) {
        result.insert(root->getKey());
        toSet(root->getLeft(), result);
        toSet(root->getRight(), result);
    }
}