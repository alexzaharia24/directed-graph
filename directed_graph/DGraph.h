#pragma once
#include <vector>
#include <unordered_map>

class DGraph {
private:
	std::unordered_map<int, std::vector<int>> inbounds;
	std::unordered_map<int, std::vector<int>> outbounds;

public:
	/* CONSTRUCTORS */
	DGraph(int n = 10);
	/* Default constructor for the DGraph class. 
			Input: n (int) - the number of vertices. */
	DGraph(const DGraph &g);
	/* Copy constructor for the DGraph class. 
			Input: g (const DGraph&) - the graph to be copied. */

	/* DESTRUCTOR */
	~DGraph();
	/* Destructor for the DGraph class. */

	/* GETTERS */
	int getNoOfVertices();
	/*	Gets the number of vertices.
			Output: (int) = number of vertices */
	int getNoOfEdges();
	/*	Gets the number of edges.
			Output: (int) = number of edges */
	int getInDegree(int x);
	/*	Gets the inbound degree of a vertix.
			Input: x (int) - the vertix we get the inbound degree for
			Output: (int) - the inbound degree of 'x' */
	int getOutDegree(int x);
	/*	Gets the outbound degree of a vertix.
			Input: x (int) - the vertix we get the outbound degree for
			Output: (int) - the outbound degree of 'x' */
	std::vector<int> getInbounds(int x);
	/*	Gets the list of inbound edges of x.
			Input: x (int) - the vertix we get the inbound edges list for
			Output: (vector<int>) - the inbound list of edges for 'x' */
	std::vector<int> getOutbounds(int x);
	/*	Gets the list of outbound edges of x.
			Input: x (int) - the vertix we get the outbound edges list for
			Output: (vector<int>) - the outbound list of edges for 'x' */

	/* ADD */
	void addEdge(int x, int y);
	/*	Add an edge between two vertixes.
			Input:	x (int) - the start vertix 
					y (int) - the end vertix */
	bool isEdge(int x, int y);
	/*	Verify if there exists an edge between 'x' and 'y' 
			Input:	x (int) - the start vertix 
					y (int) - the end vertix
			Output:	true (bool) - if there exists and edge btw 'x' and 'y' 
					false (bool - otherwise) */

	/* ITERATORS */
	std::vector<int>::iterator iteratorInBegin(int x);
	/*	Get an iterator to the begining of the inbound list of 'x'. 
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the begining 
											of the inbound list of 'x' */
	std::vector<int>::iterator iteratorInEnd(int x);
	/*	Get an iterator to the end of the inbound list of 'x'.
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the end
											of the inbound list of 'x' */
	std::vector<int>::iterator iteratorOutBegin(int x);
	/*	Get an iterator to the begining of the outbound list of 'x'.
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the begining
											of the outbound list of 'x' */
	std::vector<int>::iterator iteratorOutEnd(int x);
	/*	Get an iterator to the end of the outbound list of 'x'.
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the end
											of the outbound list of 'x' */

};