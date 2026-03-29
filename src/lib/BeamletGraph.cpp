/*
 * BeamletGraph.cpp
 *
 *  Created on: Jun 12, 2010
 *      Author: Kocher
 *      Edited by: viswans2132
 */

#include "beamlet_star_ros/BeamletGraph.h"
#include <fstream>
#include <filesystem>

BeamletGraph::BeamletGraph() {
	// TODO Auto-generated constructor stub

}

void BeamletGraph::generateBeamlets(std::map<std::vector<int>, Point*>& pointMap){
    std::vector<Point*> pointList;
	int n = pointMap.size();

    for (auto& kv : pointMap)
        pointList.push_back(kv.second);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // if (isBeamletFeasible(grid, pointList[i], pointList[j]))
            // {
                Beamlet* b = new Beamlet(pointList[i], pointList[j]);
                beamlets.push_back(b);
            // }
        }
    }
}

int BeamletGraph::getBeamletCount() const{
    return beamlets.size();
}

const std::vector<Beamlet*>& BeamletGraph::getBeamlets() const
{
    return beamlets;
}

std::string BeamletGraph::printBeamlets() const
{
    // Get current working directory (PWD)
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path filePath = cwd/"src"/"beamlet_star_ros"/"BeamletGraph"/"beamlets.txt";

    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        throw std::runtime_error("Unable to open file for writing: " + filePath.string());
    }

    int idx = 0;

    for (const Beamlet* b : beamlets)
    {
        if (!b) continue;

        const auto& p1 = b->GetPoint1()->GetCoordinates();
        const auto& p2 = b->GetPoint2()->GetCoordinates();

        // File
        outFile << "Beamlet "
                << idx << ": ("
                << p1[0] << ","
                << p1[1] << ") -> ("
                << p2[0] << ","
                << p2[1] << ")"
                << std::endl;

        idx++;
    }

    outFile.close();

    return cwd.string();
}

BeamletGraph::~BeamletGraph() {
	// TODO Auto-generated destructor stub
}