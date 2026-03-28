/*
 * DyadicObject.cpp
 *
 *  Created on: Jun 12, 2010
 *      Author: Kocher
 *      Edited by: viswans2132
 *      Modification: Beamlet Star doesn't use clusters
 */

#include "beamlet_star_ros/DyadicObject.h"

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

DyadicObject::DyadicObject(const Key & key): key(), boundaries(nullptr)
{
	this->SetKey(key);
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

DyadicObject::~DyadicObject()
{
	// TODO Auto-generated destructor stub
}