#include "DGraphCost.h"

/* CONSTRUCTORS [DGraphCost] */
DGraphCost::DGraphCost(int n) : DGraph(n) {
}
DGraphCost::DGraphCost(const DGraphCost& g) : DGraph(g) {
	this->costs = g.costs;
}
/* DESTRUCTOR [DGraphCost] */
DGraphCost::~DGraphCost() {}

/* GETTERS */
int DGraphCost::getCost(std::pair<int, int> edge) {
	return this->costs[edge];
}
std::map<std::pair<int, int>, int> DGraphCost::getCosts() {
	return this->costs;
}

/* SETTERS [DGraphCost] */
void DGraphCost::setCost(std::pair<int, int> edge, int cost) {
	this->costs[edge] = cost;
}

/* OPERATIONS [DGraphCost] */
int DGraphCost::addEdge(int x, int y, int z) {
	// (!) Add duplicate proof
	int rcode = DGraph::addEdge(x, y);
	if (rcode == 1) {
		this->costs[std::make_pair(x, y)] = z;
		return 1;
	}
	else
		return rcode;
}