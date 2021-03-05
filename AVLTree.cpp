#include "AVLTree.h"

AVLTree::AVLTree(std::vector<int> tree) {
    Node* root = nullptr;
    for (auto val : tree) {
        root = insert_element(root, val);
    }
    this->root = root;
}
 
Node* AVLTree::rightRotate(Node* y) {
    NodeAVL* yy = dynamic_cast<NodeAVL*>(y);
    NodeAVL* x = dynamic_cast<NodeAVL*>(yy->getLeft());
    NodeAVL* T2 = dynamic_cast<NodeAVL*>(x->getRight());
 
    x->setRight(yy);
    yy->setLeft(T2);

    yy->setHeight(max(dynamic_cast<NodeAVL*>(yy->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(yy->getRight())->getHeight()) + 1);
    x->setHeight(max(dynamic_cast<NodeAVL*>(x->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(x->getRight())->getHeight()) + 1);

    root = x;
    return x;
}


Node* AVLTree::leftRotate(Node* x) {
    NodeAVL* xx = dynamic_cast<NodeAVL*>(x);
    NodeAVL* y = dynamic_cast<NodeAVL*>(x->getRight());
    NodeAVL* T2 = dynamic_cast<NodeAVL*>(y->getLeft());
 
    y->setLeft(xx);
    xx->setRight(T2);

    xx->setHeight(max(dynamic_cast<NodeAVL*>(xx->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(xx->getRight())->getHeight()) + 1);
    y->setHeight(max(dynamic_cast<NodeAVL*>(y->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(y->getRight())->getHeight()) + 1);

    root = y;
    return y;
}


int AVLTree::getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return dynamic_cast<NodeAVL*>(N->getLeft())->getHeight() - dynamic_cast<NodeAVL*>(N->getRight())->getHeight();
}


Node* AVLTree::insert_element(Node* root, int key) {
    if (root == nullptr)
        return new NodeAVL(key);

    
    if (key < root->getKey())
        root->setLeft(insert_element(dynamic_cast<NodeAVL*>(root->getLeft()), key));
    else if (key > root->getKey())
        root->setRight(insert_element(dynamic_cast<NodeAVL*>(root->getRight()), key));
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


Node* AVLTree::delete_element(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->getKey())
        root->setLeft(delete_element(dynamic_cast<NodeAVL*>(root->getLeft()), key));
 
    else if (key > root->getKey())
        root->setRight(delete_element(dynamic_cast<NodeAVL*>(root->getRight()), key));
 
    else { 
        if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) {
            Node* temp = root->getLeft() ? dynamic_cast<NodeAVL*>(root->getLeft()) : dynamic_cast<NodeAVL*>(root->getRight());
  
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            free(temp);
        }
        else { 
            NodeAVL* temp = dynamic_cast<NodeAVL*>(minValueNode((root->getRight())));
            root->setKey(temp->getKey());
            root->setRight(delete_element(dynamic_cast<NodeAVL*>(root->getRight()), temp->getKey()));
        }
    }

    if (root == nullptr)
        return root;
 
    NodeAVL* rroot = dynamic_cast<NodeAVL*>(root);
    rroot->setHeight(1 + max(dynamic_cast<NodeAVL*>(rroot->getLeft())->getHeight(), dynamic_cast<NodeAVL*>(rroot->getRight())->getHeight()));

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

bool AVLTree::search_element(Node* root, int key) {
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
