#pragma once
#include "Node.h"

class NodeCartesian : public Node {
protected:
    int prior;
public:
    NodeCartesian(int, int);
    int getPrior();
    void setPrior(int);
};
