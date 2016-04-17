#pragma once
#include <map>
#include "DGraph.h"

class DGraphCost : public DGraph {
private:
	std::map<std::pair<int, int>, int> costs; //the cost
public:
	/*CONSTRUCTORS */
	DGraphCost(int n = 10);
	/*	Default constructor for the DGraphCost class.
			Input: n (int) - the number of vertices. */
	DGraphCost(const DGraphCost& g);
	/*	Copy constructor for the DGraphCost class.
			Input: g (const DGraphCost&) - the graph to be copied. */

	~DGraphCost();
	/* Destructor of the DGraphCost class. */

	/* GETTERS */
	int getCost(std::pair<int, int> edge);
	/*	Get the cost of an edge.
			Input: edge (std::pair<int, int>) - the edge represented as a std::pair of vertices
			Output: (int) - the cost of the edge. */
	std::map<std::pair<int, int>, int> getCosts();
	/*	Get the list of costs.
			Output: (map<std::pair<int, int>, int>) - the list of costs represented as a mapping
													  of std::pairs of ints to some ints. */

	/* SETTERS */
	void setCost(std::pair<int, int> edge, int cost);
	/*	Set the cost of an edge.
			Input:	edge (std::pair<int, int>) - the edge represented by a std::pair of ints
												 cost (int) - the new cost of the edge. */

	/* OPERATIONS */
	int addEdge(int x, int y, int z);
	/*	Add an edge between 'x' and 'y' with the cost 'z'.
			Input:	x (int) - the start vertix
					y (int) - the end vertix
					z (int) - the cost. 
			Output: -1 - if the edge already exists
					0  - for successful add
					1  - if the vertices out of range. */
};