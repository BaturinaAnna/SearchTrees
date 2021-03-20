#include "SplayTree.h"

SplayTree::SplayTree(set<int> tree) {
	Node* root = nullptr;
	for (auto val : tree) {
		root = insertNode(root, val);
	}
	this->root = root;
}

SplayTree::SplayTree(vector<int> tree) {
    Node* root = nullptr;
    for (auto val : tree) {
        root = insertNode(root, val);
    }
    this->root = root;
}


void SplayTree::zig(Node* x)
{
    Node* p = dynamic_cast<NodeSplay*>(x)->getParent();
    if (p->getLeft() == x) {
        Node* A = x->getLeft();
        Node* B = x->getRight();
        Node* C = p->getRight();

        dynamic_cast<NodeSplay*>(x)->setParent(nullptr);
        x->setRight(p);

        dynamic_cast<NodeSplay*>(p)->setParent(dynamic_cast<NodeSplay*>(x));
        p->setLeft(B);

        if (B != nullptr) {
            dynamic_cast<NodeSplay*>(B)->setParent(dynamic_cast<NodeSplay*>(p));
        }
    } 
    else {
        Node* A = p->getLeft();
        Node* B = x->getLeft();
        Node* C = x->getRight();

        dynamic_cast<NodeSplay*>(x)->setParent(nullptr);
        x->setLeft(p);

        dynamic_cast<NodeSplay*>(p)->setParent(dynamic_cast<NodeSplay*>(x));
        p->setRight(B);

        if (B != nullptr) {
            dynamic_cast<NodeSplay*>(B)->setParent(dynamic_cast<NodeSplay*>(p));
        }
    }
}

void SplayTree::zig_zig(Node* x)
{
    Node* p = dynamic_cast<NodeSplay*>(x)->getParent();
    Node* g = dynamic_cast<NodeSplay*>(p)->getParent();
    if (p->getLeft() == x) {
        Node* A = x->getLeft();
        Node* B = x->getRight();
        Node* C = p->getRight();

        dynamic_cast<NodeSplay*>(x)->setParent (dynamic_cast<NodeSplay*>(g)->getParent());
        x->setRight(p);

        dynamic_cast<NodeSplay*>(p)->setParent(dynamic_cast<NodeSplay*>(x));
        p->setLeft(B);
        p->setRight(g);

        dynamic_cast<NodeSplay*>(g)->setParent(dynamic_cast<NodeSplay*>(p));
        g->setLeft(C);


        if (dynamic_cast<NodeSplay*>(x)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(x)->getParent()->getLeft() == g) { 
                dynamic_cast<NodeSplay*>(x)->getParent()->setLeft(x);
            }
            else dynamic_cast<NodeSplay*>(x)->getParent()->setRight(x);
        }
        if (B != nullptr) { 
            dynamic_cast<NodeSplay*>(B)->setParent(dynamic_cast<NodeSplay*>(p)); }

        if (C != nullptr) { 
            dynamic_cast<NodeSplay*>(C)->setParent(dynamic_cast<NodeSplay*>(g)); }
    }
    else {
        Node* A = g->getLeft();
        Node* B = p->getLeft();
        Node* C = x->getLeft();

        dynamic_cast<NodeSplay*>(x)->setParent(dynamic_cast<NodeSplay*>(g)->getParent());
        x->setLeft(p);

        dynamic_cast<NodeSplay*>(p)->setParent(dynamic_cast<NodeSplay*>(x));
        p->setLeft(g);
        p->setRight(C);

        dynamic_cast<NodeSplay*>(g)->setParent(dynamic_cast<NodeSplay*>(p));
        g->setRight(B);

        if (dynamic_cast<NodeSplay*>(x)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(x)->getParent()->getLeft() == g) { 
                dynamic_cast<NodeSplay*>(x)->getParent()->setLeft(x);
            }
            else { 
                dynamic_cast<NodeSplay*>(x)->getParent()->setRight(x);
            }
        }

        if (B != nullptr) { 
            dynamic_cast<NodeSplay*>(B)->setParent(dynamic_cast<NodeSplay*>(g));
        }
        if (C != nullptr) { 
            dynamic_cast<NodeSplay*>(C)->setParent(dynamic_cast<NodeSplay*>(p));
        }
    }
}

void SplayTree::zig_zag(Node* x)
{
    Node* p = dynamic_cast<NodeSplay*>(x)->getParent();
    Node* g = dynamic_cast<NodeSplay*>(p)->getParent();
    if (p->getRight() == x) {
        Node* A = p->getLeft();
        Node* B = x->getLeft();
        Node* C = x->getRight();

        dynamic_cast<NodeSplay*>(x)->setParent(dynamic_cast<NodeSplay*>(g)->getParent());
        x->setLeft(p);
        x->setRight(g);

        dynamic_cast<NodeSplay*>(p)->setParent(dynamic_cast<NodeSplay*>(x));
        p->setRight(B);

        dynamic_cast<NodeSplay*>(g)->setParent(dynamic_cast<NodeSplay*>(x));
        g->setLeft(C);

        if (dynamic_cast<NodeSplay*>(x)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(x)->getParent()->getLeft() == g) {
                dynamic_cast<NodeSplay*>(x)->getParent()->setLeft(x);
            }
            else {
                dynamic_cast<NodeSplay*>(x)->getParent()->setRight(x);
            }
        }

        if (B != nullptr) {
            dynamic_cast<NodeSplay*>(B)->setParent(dynamic_cast<NodeSplay*>(p));
        }

        if (C != nullptr) {
            dynamic_cast<NodeSplay*>(C)->setParent(dynamic_cast<NodeSplay*>(g));
        }
    }
    else {
        Node* A = g->getLeft();
        Node* B = x->getLeft();
        Node* C = x->getRight();

        dynamic_cast<NodeSplay*>(x)->setParent(dynamic_cast<NodeSplay*>(g)->getParent());
        x->setLeft(g);
        x->setRight(p);

        dynamic_cast<NodeSplay*>(p)->setParent(dynamic_cast<NodeSplay*>(x));
        p->setLeft(C);

        dynamic_cast<NodeSplay*>(g)->setParent(dynamic_cast<NodeSplay*>(x));
        g->setRight(B);

        if (dynamic_cast<NodeSplay*>(x)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(x)->getParent()->getLeft() == g) {
                dynamic_cast<NodeSplay*>(x)->getParent()->setLeft(x);
            }
            else {
                dynamic_cast<NodeSplay*>(x)->getParent()->setRight(x);
            }
        }

        if (B != nullptr) {
            dynamic_cast<NodeSplay*>(B)->setParent(dynamic_cast<NodeSplay*>(g));
        }

        if (C != nullptr) {
            dynamic_cast<NodeSplay*>(C)->setParent(dynamic_cast<NodeSplay*>(p));
        }
    }
}

Node* SplayTree::splay(Node* x)
{
    while (dynamic_cast<NodeSplay*>(x)->getParent() != nullptr) {
        Node* p = dynamic_cast<NodeSplay*>(x)->getParent();
        Node* g = dynamic_cast<NodeSplay*>(p)->getParent();
        if (g == nullptr) {
            zig(x);
        }
        else if (g->getLeft() == p && p->getLeft() == x) { 
            zig_zig(x); 
        }
        else if (g->getRight() == p && p->getRight() == x) {
            zig_zig(x);
        }
        else { 
            zig_zag(x); 
        }
    }
    this->root = x;
    return this->root;
}

Node* SplayTree::insertNode(Node* root, int key){
	if (root == nullptr) {
		Node* newNode = new NodeSplay(key);
		this->root = newNode;
		return newNode;
	}
    Node* current = this->root;
	while (current != nullptr) {
		if (key < current->getKey()) {
			if (current->getLeft() == nullptr) {
                Node* newNode = new NodeSplay(key);
				current->setLeft(newNode);
                dynamic_cast<NodeSplay*>(newNode)->setParent(dynamic_cast<NodeSplay*>(current));
				splay(newNode);
				return newNode;
			}
			else current = current->getLeft();
		}
		else if (key > current->getKey()) {
			if (current->getRight() == nullptr){
                Node* newNode = new NodeSplay(key);
				current->setRight(newNode);
                dynamic_cast<NodeSplay*>(newNode)->setParent(dynamic_cast<NodeSplay*>(current));
				splay(newNode);
				return newNode;
			}
			else current = current->getRight();
		}
		else {
			splay(current);
            return current;
		}
	}



}

Node* SplayTree::deleteNode(Node* root, int key)
{
    if (root == nullptr)
        return root;
    Node* del = nullptr;
    Node* curr = root;
    Node* prev = nullptr;
    while (curr != nullptr) {
        prev = curr;
        if (key < curr->getKey()) {
            curr = curr->getLeft();
        }
        else if (key > curr->getKey()) {
            curr = curr->getRight();
        }
        else {
            del = curr;
            break;
        }
    }
    if (del == nullptr) {
        return nullptr;
    }

    Node* L = del->getLeft();
    Node* R = del->getRight();
    if (L == nullptr && R == nullptr) {
        if (dynamic_cast<NodeSplay*>(del)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(del)->getParent()->getLeft() == del) {
                dynamic_cast<NodeSplay*>(del)->getParent()->setLeft(nullptr);
            }
            else {
                dynamic_cast<NodeSplay*>(del)->getParent()->setRight(nullptr);
            }
        }
        else {
            this->root = nullptr;
        }
    }
    else if (L == nullptr) {
        if (dynamic_cast<NodeSplay*>(del)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(del)->getParent()->getLeft() == del) {
                dynamic_cast<NodeSplay*>(del)->getParent()->setLeft(R);
            }
            else {
                dynamic_cast<NodeSplay*>(del)->getParent()->setRight(R);
            }
            dynamic_cast<NodeSplay*>(R)->setParent(dynamic_cast<NodeSplay*>(del)->getParent());

            splay(dynamic_cast<NodeSplay*>(R)->getParent());
        }
        else {
            root = R;
            dynamic_cast<NodeSplay*>(R)->setParent(nullptr);
        }
    }
    else if (R == nullptr) {
        if (dynamic_cast<NodeSplay*>(del)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(del)->getParent()->getLeft() == del) {
                dynamic_cast<NodeSplay*>(del)->getParent()->setLeft(L);
            }
            else {
                dynamic_cast<NodeSplay*>(del)->getParent()->setRight(L);
            }
            dynamic_cast<NodeSplay*>(L)->setParent(dynamic_cast<NodeSplay*>(del)->getParent());

            Node* M = L;
            while (M->getRight() != nullptr) {
                M = M->getRight();
            }
            splay(M);
        }
        else {
            root = L;
            dynamic_cast<NodeSplay*>(L)->setParent(nullptr);
        }
    }
    else {
        Node* M = L;
        while (M->getRight() != nullptr) {
            M = M->getRight();
        }
        if (dynamic_cast<NodeSplay*>(del)->getParent() != nullptr) {
            if (dynamic_cast<NodeSplay*>(del)->getParent()->getLeft() == del) {
                dynamic_cast<NodeSplay*>(del)->getParent()->setLeft(L);
            }
            else {
                dynamic_cast<NodeSplay*>(del)->getParent()->setRight(L);
            }
            dynamic_cast<NodeSplay*>(L)->setParent(dynamic_cast<NodeSplay*>(del)->getParent());
        }
        else {
            root = L;
            dynamic_cast<NodeSplay*>(L)->setParent(nullptr);
        }
        M->setRight(R);
        dynamic_cast<NodeSplay*>(R)->setParent(dynamic_cast<NodeSplay*>(M));
        splay(M);

    }
}

bool SplayTree::searchNode(Node* root, int key)
{
    Node* ret = nullptr;
    Node* curr = root;
    Node* prev = nullptr;
    while (curr != nullptr) {
        prev = curr;
        if (key < curr->getKey()) {
            curr = curr->getLeft();
        }
        else if (key > curr->getKey()) {
            curr = curr->getRight();
        }
        else {
            ret = curr;
            break;
        }
    }
    if (ret != nullptr) {
        splay(ret);
        return true;
    }
    return false;
}

void SplayTree::print(Node* root) {
	if (root != nullptr) {
		cout << root->getKey() << " ";
		print(root->getLeft());
		print(root->getRight());
	}
}

void SplayTree::toSet(Node* root, set<int>& result) {
	if (root != nullptr) {
		result.insert(root->getKey());
		toSet(root->getLeft(), result);
		toSet(root->getRight(), result);
	}
}

Node* SplayTree::getRoot() {
	return this->root;
}