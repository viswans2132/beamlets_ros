#include "QuadTreeNode.h"

using namespace std;

// Initialize a quadtree node
QuadTreeNode::QuadTreeNode(int s, int x, int y)
    : s(s), x(x), y(y), obstacleCount(0), color("GRAY")
{
    for (int i = 0; i < 4; i++)
        children[i] = nullptr;
}
