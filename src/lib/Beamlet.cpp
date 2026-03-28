/*
 * Beamlet.cpp
 *
 *  Edited by: viswans2132
 */

#include "beamlet_star_ros/Beamlet.h"
// #include "utilities/PrintContent.h"

Beamlet::Beamlet(): neighborBeamletList()
{
	this->point1 = NULL;
	this->point2 = NULL;
	//this->neighborBeamletList = NULL;
	this->neighborBeamletsComputed = false;
}


Beamlet::Beamlet(Point* point1, Point* point2): neighborBeamletList()
{
	this->point1 = point1;
	this->point2 = point2;
	//this->neighborBeamletList = NULL;
	this->neighborBeamletsComputed = false;
}

/*
std::list<Beamlet*> *
Beamlet::GetNeighborBeamlets(BeamletGraph* beamletGraph)
{
	if (this->neighborBeamletsComputed == true)
        return this->neighborBeamletList;
    else
	{
		std::list<Beamlet*> *neighborBeamletList;
        std::list<Point*> *pairPointList;
		std::list<Beamlet*> *beamletList;
		int len;

		neighborBeamletList = new std::list<Beamlet*>();


		pairPointList =	this->GetPoint1()->GetPairPoints(beamletGraph);


		len = pairPointList->size();

		// use iterators


        for(std::list<Point*>::iterator it = pairPointList->begin();
        	it != pairPointList->end(); ++it)
		{
            beamletList = (*it)->GetBeamletList();
			neighborBeamletList->insert(neighborBeamletList->end(), beamletList->begin(), beamletList->end());
		}

        pairPointList = this->GetPoint2()->GetPairPoints(beamletGraph);

		len = pairPointList->size();

		// use iterators
		for(std::list<Point*>::iterator it = pairPointList->begin();
			it != pairPointList->end(); ++it)
		{
            beamletList = (*it)->GetBeamletList();
			neighborBeamletList->insert(neighborBeamletList->end(), beamletList->begin(), beamletList ->end());
		}

        // TODO: think about necessity of sycronize all beamlets'
        // neighborBeamletList
        this->neighborBeamletList = neighborBeamletList;
        this->neighborBeamletsComputed = true;

		return this->neighborBeamletList;
	}

}
*/


// std::ostream&
// operator<<(std::ostream & output, const Beamlet & beamlet)
// {
// 	if (beamlet.point1)
// 	{
// 		std::vector<int> const & coor1 = beamlet.point1->GetCoordinates();

// 		if (!coor1.empty())
// 			output << coor1;
// 		else
// 			output << "[ .. ]";
// 	}
// 	else
// 		output << "[ .. ]";

// 	output << " - ";

// 	if (beamlet.point2)
// 	{
// 		std::vector<int> const & coor2 = beamlet.point2->GetCoordinates();

// 		if (!coor2.empty())
// 			output << coor2;
// 		else
// 			output << "[ .. ]";
// 	}
// 	else
// 		output << "[ .. ]";

// 	return output;
// }

Beamlet::~Beamlet()
{
}


