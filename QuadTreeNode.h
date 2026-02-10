#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Each dyadic square is characterized by a 3 tuple (s; x, y) where s is the scale and (x, y) are the coordinates of the dyadic square
class QuadTreeNode
{
public:
    int s;                 
    int x, y;              
    int obstacleCount;     // Number of obstacles in the dyadic square
    string color;     // Color of node of dyadic square: WHITE(free), GRAY(mix), BLACK(occupied)
    QuadTreeNode* children[4]; // Each dyadic sqaure node has 4 children, which are the four quadrants of the square

    QuadTreeNode(int scale, int dx, int dy);

    ~QuadTreeNode();
};

#endif
