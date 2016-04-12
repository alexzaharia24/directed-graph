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
void DGraphCost::addEdge(int x, int y, int z) {
	DGraph::addEdge(x, y);
	this->costs[std::make_pair(x, y)] = z;
}