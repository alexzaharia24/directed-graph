#include "DGraph.h"
/* CONSTRUCTORS [DGraph] */
DGraph::DGraph(int n) {
	int i;
	for (i = 0; i<n; i++) {
		this->inbounds[i] = std::vector<int>();
		this->outbounds[i] = std::vector<int>();
	}
}
DGraph::DGraph(const DGraph& g) {
	this->inbounds = g.inbounds;
	this->outbounds = g.outbounds;
}

/* DESTRUCTOR [DGraph] */
DGraph::~DGraph() {
}

/* GETTERS [DGraph] */
int DGraph::getNoOfVertices() {
	return this->inbounds.size();
}
int DGraph::getNoOfEdges() {
	int no = 0;
	for (int i = 0; i < this->getNoOfVertices(); i++) {
		no += this->inbounds[i].size() + this->outbounds[i].size();
	}
	return no / 2;
}
int DGraph::getInDegree(int x) {
	return this->inbounds[x].size();
}
int DGraph::getOutDegree(int x) {
	return this->outbounds[x].size();
}
std::vector<int> DGraph::getInbounds(int x) {
	return this->inbounds[x];
}
std::vector<int> DGraph::getOutbounds(int x) {
	return this->outbounds[x];
}

/* ADD [DGraph] */
int DGraph::addEdge(int x, int y) {
	if (x > this->getNoOfVertices() || y > this->getNoOfVertices()) {
		return 0;
	}
	else if (isEdge(x, y)) {
		return -1;
	}
	this->inbounds[y].push_back(x);
	this->outbounds[x].push_back(y);
	return 1;
}
bool DGraph::isEdge(int x, int y) {
	if (find(this->inbounds[y].begin(), this->inbounds[y].end(), x) != this->inbounds[y].end()) {
		return 1;
	}
	return 0;
}

/* ITERATORS [DGraph] */
std::vector<int>::iterator DGraph::iteratorInBegin(int x) {
	return this->inbounds[x].begin();
}
std::vector<int>::iterator DGraph::iteratorInEnd(int x) {
	return this->inbounds[x].end();
}
std::vector<int>::iterator DGraph::iteratorOutBegin(int x) {
	return this->outbounds[x].begin();
}
std::vector<int>::iterator DGraph::iteratorOutEnd(int x) {
	return this->outbounds[x].end();
}