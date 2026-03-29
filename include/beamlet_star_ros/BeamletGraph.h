/*
 * BeamletGraph.h
 *
 *  Created on: Jun 12, 2010
 *      Author: Kocher
 *      Edited by: viswans2132
 */

#ifndef BEAMLETGRAPH_H_
#define BEAMLETGRAPH_H_

#include <vector>
#include <map>
#include "beamlet_star_ros/Point.h"
#include "beamlet_star_ros/Beamlet.h"
#include <string>

class BeamletGraph {
public:
	std::vector<Beamlet*> beamlets;

	BeamletGraph();
	
	void generateBeamlets(std::map<std::vector<int>, Point*>& pointMap);

	int getBeamletCount() const;

	const std::vector<Beamlet*>& getBeamlets() const;

	std::string printBeamlets() const;

	~BeamletGraph();
};

#endif /* BEAMLETGRAPH_H_ */