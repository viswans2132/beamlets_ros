/**
 * Author: viswans2132
 * File: quadtree.cpp
 */

#include "beamlet_star_ros/quadtree.h"
#include "beamlet_star_ros/DyadicObject.h"
#include "rclcpp/rclcpp.hpp"

#include <cmath>

QuadTree::QuadTree()
    : root(nullptr)
{
}

DyadicObject* QuadTree::getQTRoot() const{
    return root;
}

int QuadTree::countObstacles(DyadicObject* node, const std::vector<std::vector<int>>& grid) const
{
    Key k = node->GetKey();

    int scale = k.scale;
    int size = static_cast<int>(pow(2, scale));

    int x = k.position[0];
    int y = k.position[1];
    int rowStart = (x-1)*size;
    int colStart = (y-1)*size;

    int count = 0;
    for (int i = rowStart; i < rowStart + size; ++i){
        for (int j = colStart; j < colStart + size; ++j){
            if (i >= 0 && i < static_cast<int>(grid.size()) &&
            j >= 0 && j < static_cast<int>(grid[0].size()))
            {
                if (grid[i][j] == 1)
                    ++count;
            }
        }
    }

    return count;
}

DyadicObject* QuadTree::buildQuadTree(std::vector<std::vector<int>>& grid, int scale, int x, int y, int alpha)
{
    DyadicObject* node = new DyadicObject(Key(scale, {x, y}));

    if(root == nullptr)
        root = node;

    node->setBoundaries(grid.size(), grid[0].size());

    int totalObstacles = countObstacles(node, grid);
    node->setObstacleCount(totalObstacles);

    int totalCells = pow(2, 2*scale);

    if(totalObstacles == 0) {
        node->setColor("WHITE");
        leaves.push_back(node);
    } else if(totalObstacles == totalCells) {
        node->setColor("BLACK");
        leaves.push_back(node);
    } else{
        node->setColor("GRAY");

        if(scale == 0)
        {
            leaves.push_back(node);
            return node;
        }

        double lowerLimit = 1 + alpha*(pow(2,2*scale-1) - 1);
        double upperLimit = totalCells - 1 - alpha*(pow(2,2*scale-1) - 1);

        if((totalObstacles < lowerLimit || totalObstacles > upperLimit))
        {
            leaves.push_back(node);
            return node;
        }

        else{
            node->setChild(0, buildQuadTree(grid, scale-1, 2*x-1, 2*y-1, alpha));
            node->setChild(1, buildQuadTree(grid, scale-1, 2*x-1, 2*y, alpha));
            node->setChild(2, buildQuadTree(grid, scale-1, 2*x, 2*y-1, alpha));
            node->setChild(3, buildQuadTree(grid, scale-1, 2*x, 2*y, alpha));
        }
    }

    return node;
}

void QuadTree::printFormalDyadicForm(DyadicObject* node) const
{
    if(node == nullptr) 
        return;

    auto logger = rclcpp::get_logger("Formal Dyadic Form");

    Key k = node->GetKey();
    int scale = k.scale;
    int x = k.position[0];
    int y = k.position[1];

    if(node->isLeaf()) {
        RCLCPP_INFO(logger, "q(%d;%d,%d) = %s",
                    scale,
                    x,
                    y,
                    node->getColor().c_str());
        return;
    } else{
        std::string line = "q(" + std::to_string(scale) + ";" +
                        std::to_string(x) + "," +
                        std::to_string(y) + ") = " +
                        "q(" + std::to_string(scale-1) + ";" +
                        std::to_string(2*x-1) + "," +
                        std::to_string(2*y-1) + ") ∪ " +
                        "q(" + std::to_string(scale-1) + ";" +
                        std::to_string(2*x-1) + "," +
                        std::to_string(2*y) + ") ∪ " +
                        "q(" + std::to_string(scale-1) + ";" +
                        std::to_string(2*x) + "," +
                        std::to_string(2*y-1) + ") ∪ " +
                                                "q(" + std::to_string(scale-1) + ";" +
                        std::to_string(2*x) + "," +
                        std::to_string(2*y) + ")";

        RCLCPP_INFO(logger, "%s", line.c_str());

        for(int i=0; i<4; i++)
            printFormalDyadicForm(node->getChild(i));
    }
}

void QuadTree::printLeafBoundaries() const
{
    auto logger = rclcpp::get_logger("Leaf Boundaries");

    for(const auto* node : leaves)
    {
        int** boundaries = node->getBoundaries();

        if (!boundaries)
            continue;

        Key k = node->GetKey();

        RCLCPP_INFO(logger,
            "Leaf q(%d;%d,%d,%s) boundaries:",
            k.scale,
            k.position[0],
            k.position[1],
            node->getColor().c_str());

        RCLCPP_INFO(logger, "  TL: (%d,%d)", boundaries[0][0], boundaries[0][1]);
        RCLCPP_INFO(logger, "  TR: (%d,%d)", boundaries[1][0], boundaries[1][1]);
        RCLCPP_INFO(logger, "  BL: (%d,%d)", boundaries[2][0], boundaries[2][1]);
        RCLCPP_INFO(logger, "  BR: (%d,%d)", boundaries[3][0], boundaries[3][1]);
    }
}

const std::vector<DyadicObject*>& QuadTree::getLeaves() const { 
    return leaves; 
}

QuadTree::~QuadTree()
{
    // TODO Auto-generated destructor stub
}