// /*
//  * main.cpp
//  *
//  *  Created on: Jun 12, 2010
//  *      Author: Kocher
//  */

// #include <iostream>
// #include <cmath>
// #include <vector>

// #include "utilities/PrintContent.h"
// #include "utilities/utilities.h"

// void
// testPoint();

// void
// testBeamlet();

// void
// testCluster();

// void
// testToBase();



// int main()
// {
// 	//std::cout << "Hello world!" << std::endl;


// 	//testPoint();

// 	//testBeamlet();

// 	testCluster();

// 	std::string type("X");

// 	size_t found;

// 	found = type.find("X");
// 	std::vector<int> fctIndex;

// 	while (found!=std::string::npos)
// 	{
// 		fctIndex.push_back(found);
// 		found = type.find("X", found+1);
// 	}

// 	std::cout << fctIndex << std::endl;


// 	/*
// 	int startArray[] = {1, 1, 1}, goalArray[] = {4, 4, 1} ;

// 	std::vector<int> start(startArray, startArray + sizeof(startArray)/(sizeof(int))),
// 					 goal(goalArray, goalArray + sizeof(goalArray)/(sizeof(int)));;


// 	int n = goal.size();
// 	std::vector<int> state = start;
// 	int i = n-1;

// 	while (state[0] <= goal[0])
// 	{

// 		std::cout << state << std::endl;

// 		state[i] = state[i] + 1;

// 		while(state[i] > goal[i])
// 		{
// 			if (i == 0)
// 				break;

// 			state[i] = start[i];
// 			i = i - 1;
// 			state[i] = state[i] + 1;
// 		}

// 		i = n-1;
// 	}
// 	*/

// 	//testToBase();

// 	char buffer[32];

// 	toBase( 9, buffer, 2, 10 );

// 	int coorArray [] = {1, 2, 3};

// 	std::vector<int> coor (coorArray, coorArray + sizeof(coorArray)/sizeof(int) );


// 	int dim = coor.size();
// 	int index = 0;
// 	int maxSize = 7;

// 	for (int i = 0; i < dim; ++i)
// 		index = index + coor[i]*pow(maxSize, dim - 1 -i);

// 	std::cout << index << std::endl;




// 	return 0;
// }


#include <iostream>
#include "QuadTreeBuilder.h"
#include "QuadTreeHelper.h"
#include "config.h"

using namespace std;

int main() {
    // Create the QuadTree object
    QuadTree qt;

    // Build the quadtree starting from scale smax and top-left (1,1)
    QuadTreeNode* root = qt.buildQuadTree(Config::smax, 1, 1);

    cout << "\n===== QUADTREE STRUCTURE =====\n\n";

    // Create a helper object to print the quadtree
    QuadTreeHelper helper;
    // helper.printQuadTree(root, 0);
	helper.printFormalDyadicForm(root);

    return 0;
}

