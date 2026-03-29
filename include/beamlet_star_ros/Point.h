/*
 * Point.h
 *
 *  Edited by: viswans2132
 *  Modification: Beamlet Star doesn't use clusters
 */

 #ifndef POINT_H_
#define POINT_H_

#include <vector>
#include <list>
#include <algorithm>
#include "beamlet_star_ros/Beamlet.h"
// #include "Cluster.h"
#include "beamlet_star_ros/BeamletGraph.h"

#include <iostream>
#include <map>

class Beamlet;
// class Cluster;

class Point
{

private:
	std::vector<int> coordinates;
	std::list<Beamlet*> beamletList;

	// Cluster *parentCluster;
	std::list<Point*> pairPointList;
	bool pairPointsComputed;

public:

	Point();
	Point(const std::vector<int> & coordinates);
	// Point(const std::vector<int> & coordinates, Cluster *parentCluster);

	void
	AddBeamlet(Beamlet* beamlet);

	void
	RemoveBeamlet(const std::vector<int> & coordinates);

	std::list<Beamlet*>
	GetBeamletList() const;

	std::vector<int>
	GetCoordinates() const;

	void
	AddPairPoints(Point *pairPoint);

	void
	AddPairPoints(std::list<Point*> const& pairPoints);

	void
	SetPairPointsComputed(bool value);

	//TODO: test GetPairPoints function
	// std::list<Point*> *
	// GetPairPoints(BeamletGraph *beamletGraph);

	friend std::ostream& operator<<(std::ostream& output, const Point& point);

	void static generateNewPoint(std::map<std::vector<int>, Point*>& pointMap,
							   std::vector<int> coordinates);

	~Point(void);

};

#endif /* POINT_H_ */

