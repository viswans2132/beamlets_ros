/*
 * DyadicObject.cpp
 *
 *  Created on: Jun 12, 2010
 *      Author: Kocher
 *      Edited by: viswans2132
 *      Modification: Beamlet Star doesn't use clusters
 */

#include "beamlet_star_ros/DyadicObject.h"
#include <cmath>

// DyadicObject::DyadicObject(): key(), clusterList(), boundaries(NULL)
// {
// 	// TODO Auto-generated constructor stub

// }

// DyadicObject::DyadicObject(const Key & key): key(), clusterList() boundaries(NULL)
// {
// 	this->SetKey(key);
// 	int spaceDim = key.position.size();
// 	int totalNumberClusters = pow(3, spaceDim) - 1;

// 	this->clusterList.reserve(totalNumberClusters);

// 	for (int k = 0; k < totalNumberCLusters; ++k)
// 		this->clusterList.push_back(NULL);
// }

DyadicObject::DyadicObject(): key(), boundaries(nullptr)
{
	// TODO Auto-generated constructor stub

}

DyadicObject::DyadicObject(const Key & key): key(), boundaries(nullptr), obstacleCount(0), color("GRAY")
{
	this->SetKey(key);
	for(int i=0; i<4; i++)
        children[i] = nullptr;
}

Key
DyadicObject::GetKey() const
{
	return this->key;
}

void
DyadicObject::SetKey(int scale, const std::vector<int> & position)
{
	this->key.scale = scale;
	this->key.position = position;
}

void
DyadicObject::SetKey(const Key& key)
{
	this->key.scale = key.scale;
	this->key.position = key.position;
}

void DyadicObject::setBoundaries(int totalRows, int totalCols)
{
    boundaries = new int*[4];
    for (int i = 0; i < 4; ++i)
        boundaries[i] = new int[2];

    int scale = key.scale;
    int x = key.position[0];
    int y = key.position[1];
    int size = static_cast<int>(pow(2, scale));

    int rowStart = (x - 1) * size; // 1-based
    int colStart = (y - 1) * size;

    boundaries[0][0] = rowStart;            
    boundaries[0][1] = colStart;             // TL
    boundaries[1][0] = rowStart;            
    boundaries[1][1] = colStart + size;  	 // TR
    boundaries[2][0] = rowStart + size; 
    boundaries[2][1] = colStart;             // BL
    boundaries[3][0] = rowStart + size; 
    boundaries[3][1] = colStart + size;  	 // BR

    for(int i = 0; i < 4; ++i)
    {
        boundaries[i][0] = std::min(boundaries[i][0], totalRows);
        boundaries[i][1] = std::min(boundaries[i][1], totalCols);
    }
}

int** DyadicObject::getBoundaries() const
{
    return boundaries;
}

void DyadicObject::setObstacleCount(int totalObstacles) { 
    obstacleCount = totalObstacles; 
}

int DyadicObject::getObstacleCount() const { 
    return obstacleCount; 
}

void DyadicObject::setColor(const std::string& c) {
    color = c; 
}

std::string DyadicObject::getColor() const { 
    return color; 
}

void DyadicObject::setChild(int index, DyadicObject* child) { 
    children[index] = child;
}

DyadicObject* DyadicObject::getChild(int index) const { 
    return children[index]; 
}

bool DyadicObject::isLeaf() const{
    if(getChild(0) == nullptr)
        return true;
    return false;
}

DyadicObject::~DyadicObject()
{
	// TODO Auto-generated destructor stub
	if (boundaries)
    {
        for (int i = 0; i < 4; ++i)
            delete[] boundaries[i];
        delete[] boundaries;
        boundaries = nullptr;
    }
}