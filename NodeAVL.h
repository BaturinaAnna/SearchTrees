#pragma once
#include "Node.h"

class NodeAVL: public Node {
protected:
    int height;
public:
    NodeAVL(int);
    int getHeight();
    void setHeight(int);
};
