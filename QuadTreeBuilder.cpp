#include "QuadTreeBuilder.h"
#include "QuadTreeHelper.h"
#include "config.h"

using namespace std;

QuadTreeNode* QuadTree::getRoot()
{
    return root;
}

QuadTreeNode* QuadTree::buildQuadTree(int s, int x, int y)
{
    QuadTreeNode* node = new QuadTreeNode(s,x,y);

    int totalObstacles = QuadTreeHelper().countObstacles(s, x, y);
    node->obstacleCount = totalObstacles;

    int totalCells = pow(2, 2*s);

    if(totalObstacles == 0) { // no obstacles in the square, hence, no need to subdivide further
        node->color = "WHITE";
    }

    else if(totalObstacles == totalCells) { // all cells in the square are obstacles, hence, no need to subdivide further
        node->color = "BLACK";
    }

    else{
        node->color = "GRAY"; // mix

        if(s == 0) // if lowest scale, dont divide further
            return node;

        double lowerLimit = 1 + Config::alpha*(pow(2,2*s-1) - 1);
        double upperLimit = totalCells - 1 - Config::alpha*(pow(2,2*s-1) - 1);

        if((totalObstacles < lowerLimit || totalObstacles > upperLimit)) // if number of obstacles in the dyadic sqaure are not in range, dont divide further
            return node;

        else{ // else divide further
            node->children[0] = buildQuadTree(s-1, 2*x-1, 2*y-1);
            node->children[1] = buildQuadTree(s-1, 2*x-1, 2*y);
            node->children[2] = buildQuadTree(s-1, 2*x, 2*y-1);
            node->children[3] = buildQuadTree(s-1, 2*x, 2*y);
        }
    }

    return node;
}