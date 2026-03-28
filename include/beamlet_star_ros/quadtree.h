
/**
 * Author: viswans2132
 * File: quadtree.h
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "beamlet_star_ros/DyadicObject.h"

class QuadTree
{
private:
    DyadicObject* root;
    std::vector<DyadicObject*> leaves;

public:

    QuadTree();

    DyadicObject* getQTRoot() const;

    int countObstacles(DyadicObject* node, const std::vector<std::vector<int>>& grid) const;

    DyadicObject* buildQuadTree(std::vector<std::vector<int>>& grid, int scale, int x, int y, int alpha);

    void printFormalDyadicForm(DyadicObject* node) const;

    void printLeafBoundaries() const;

    const std::vector<DyadicObject*>& getLeaves() const;
    
    ~QuadTree();
};

#endif