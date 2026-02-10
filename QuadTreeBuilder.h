#ifndef QUADTREE_H
#define QUADTREE_H

#include "QuadTreeNode.h"

class QuadTree
{
private:
    QuadTreeNode* root;

public:

    QuadTreeNode* buildQuadTree(int s, int x, int y);

    QuadTreeNode* getRoot();
};

#endif
