/**
 * Author: viswans2132
 * File: quadtree.h
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "beamlet_star_ros/DyadicObject.h"
#include "beamlet_star_ros/Point.h"
#include <vector>
#include <map>

class QuadTree
{
private:
    DyadicObject* root;
    std::vector<DyadicObject*> leaves;
    std::map<std::vector<int>, Point*> pointMap;

public:

    QuadTree();

    DyadicObject* getQTRoot() const;

    int countObstacles(DyadicObject* node, const std::vector<std::vector<int>>& grid) const;

    DyadicObject* buildQuadTree(std::vector<std::vector<int>>& grid, int scale, int x, int y, int alpha);

    void printFormalDyadicForm(DyadicObject* node) const;

    void printLeafCorners() const;

    const std::vector<DyadicObject*>& getLeaves() const;
    
    void addLeafBoundaryPoints(DyadicObject* node);

    std::map<std::vector<int>, Point*> getUniqueLeafPoints() const;

    void printUniquePoints(std::map<std::vector<int>, Point*>& pointMap) const;

    ~QuadTree();
};

#endif