#pragma once
#include "Node.h"

class NodeSplay : public Node {
protected:
    NodeSplay* parent;
public:
    NodeSplay(int);
    NodeSplay* getParent();
    void setParent(NodeSplay*);
};