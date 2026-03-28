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

class DyadicObject
{
private:
	Key key;
	// std::vector<Cluster*> clusterList;
	int **boundaries;

public:
	DyadicObject();
	DyadicObject(const Key & key);

	Key
	GetKey() const;

	void
	SetKey(int scale, const std::vector<int> & position);

	void
	SetKey(const Key& key);

	~DyadicObject();
};

#endif /* DYADICOBJECT_H_ */