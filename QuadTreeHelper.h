#include "QuadTreeNode.h"

using namespace std;

class QuadTreeHelper{
public:
    int countObstacles(int s, int x, int y) const;

    void printQuadTree(QuadTreeNode* node, int depth) const;

    void printFormalDyadicForm(QuadTreeNode* node) const;   

};