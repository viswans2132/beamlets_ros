/*
 * Key.h
 *
 *  Edited by: viswans2132
 *  Modification: Beamlet Star doesn't use clusters
 */

 #ifndef DYADICOBJECT_H_
#define DYADICOBJECT_H_

// #include "Cluster.h"
#include "beamlet_star_ros/Key.h"
#include <string>

class DyadicObject
{
private:
	Key key;
	// std::vector<Cluster*> clusterList;
	int **boundaries;
	int obstacleCount;
	std::string color;
	DyadicObject* children[4];

public:
	DyadicObject();
	DyadicObject(const Key & key);

	Key
	GetKey() const;

	void
	SetKey(int scale, const std::vector<int> & position);

	void
	SetKey(const Key& key);

	void setBoundaries(int totalRows, int totalCols);

	int** getBoundaries() const;
	
	void setObstacleCount(int totalObstacles);

	int getObstacleCount() const;

	void setColor(const std::string& color);

	std::string getColor() const;

	void setChild(int index, DyadicObject* child);

	DyadicObject* getChild(int index) const;

	bool isLeaf() const;

	~DyadicObject();
};

#endif /* DYADICOBJECT_H_ */