#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/* ====== DGraph ======*/
class DGraph {
private:
	unordered_map<int, vector<int>> inbounds;
	unordered_map<int, vector<int>> outbounds;

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
	vector<int> getInbounds(int x);
	/*	Gets the list of inbound edges of x.
			Input: x (int) - the vertix we get the inbound edges list for
			Output: (vector<int>) - the inbound list of edges for 'x' */
	vector<int> getOutbounds(int x);
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
	vector<int>::iterator iteratorInBegin(int x);
	/*	Get an iterator to the begining of the inbound list of 'x'. 
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the begining 
											of the inbound list of 'x' */
	vector<int>::iterator iteratorInEnd(int x);
	/*	Get an iterator to the end of the inbound list of 'x'.
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the end
											of the inbound list of 'x' */
	vector<int>::iterator iteratorOutBegin(int x);
	/*	Get an iterator to the begining of the outbound list of 'x'.
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the begining
											of the outbound list of 'x' */
	vector<int>::iterator iteratorOutEnd(int x);
	/*	Get an iterator to the end of the outbound list of 'x'.
			Input: x (int) - the vertix we work with
			Output: (vector<int>::iterator) - iterator to the end
											of the outbound list of 'x' */

};

/* CONSTRUCTORS [DGraph] */
DGraph::DGraph(int n) {
	int i;
	for (i = 0; i<n; i++) {
		this->inbounds[i] = vector<int>();
		this->outbounds[i] = vector<int>();
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
vector<int> DGraph::getInbounds(int x) {
	return this->inbounds[x];
}
vector<int> DGraph::getOutbounds(int x) {
	return this->outbounds[x];
}

/* ADD [DGraph] */
void DGraph::addEdge(int x, int y) {
	this->inbounds[y].push_back(x);
	this->outbounds[x].push_back(y);
}
bool DGraph::isEdge(int x, int y) {
	if (find(this->inbounds[y].begin(), this->inbounds[y].end(), x) != this->inbounds[y].end()) {
		return 1;
	}
	return 0;
}

/* ITERATORS [DGraph] */
vector<int>::iterator DGraph::iteratorInBegin(int x) {
	return this->inbounds[x].begin();
}
vector<int>::iterator DGraph::iteratorInEnd(int x) {
	return this->inbounds[x].end();
}
vector<int>::iterator DGraph::iteratorOutBegin(int x) {
	return this->outbounds[x].begin();
}
vector<int>::iterator DGraph::iteratorOutEnd(int x) {
	return this->outbounds[x].end();
}

/* ====== DGraphCost ======*/
class DGraphCost : public DGraph {
private:
	map<pair<int, int>, int> costs; //the cost
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
	int getCost(pair<int, int> edge);
	/*	Get the cost of an edge. 
			Input: edge (pair<int, int>) - the edge represented as a pair of vertices
			Output: (int) - the cost of the edge. */
	map<pair<int, int>, int> getCosts();
	/*	Get the list of costs. 
			Output: (map<pair<int, int>, int>) - the list of costs represented as a mapping
												of pairs of ints to some ints. */

	/* SETTERS */
	void setCost(pair<int, int> edge, int cost);
	/*	Set the cost of an edge. 
			Input:	edge (pair<int, int>) - the edge represented by a pair of ints
					cost (int) - the new cost of the edge. */

	/* OPERATIONS */
	void addEdge(int x, int y, int z);
	/*	Add an edge between 'x' and 'y' with the cost 'z'. 
			Input:	x (int) - the start vertix
					y (int) - the end vertix
					z (int) - the cost. */
};

/* CONSTRUCTORS [DGraphCost] */
DGraphCost::DGraphCost(int n) : DGraph(n) {
}
DGraphCost::DGraphCost(const DGraphCost& g) : DGraph(g) {
	this->costs = g.costs;
}
/* DESTRUCTOR [DGraphCost] */
DGraphCost::~DGraphCost() {}

/* GETTERS */
int DGraphCost::getCost(pair<int, int> edge) {
	return this->costs[edge];
}
map<pair<int, int>, int> DGraphCost::getCosts() {
	return this->costs;
}

/* SETTERS [DGraphCost] */
void DGraphCost::setCost(pair<int, int> edge, int cost) {
	this->costs[edge] = cost;
}

/* OPERATIONS [DGraphCost] */
void DGraphCost::addEdge(int x, int y, int z) {
	DGraph::addEdge(x, y);
	this->costs[make_pair(x, y)] = z;
}

/* ------- UI -------- */
void readEdgeG(DGraph &g) {
	/*	Read an edge from the user and add it to the graph. 
			Input: g (DGraph&) - the graph we will add the edge to. */
	int a, b;
	cout << "v-v \n";
	cin >> a >> b;
	g.addEdge(a, b);
}
void readEdgeGC(DGraph &g) {
	/*	Read an edge from the user and add it to the graph.
	Input: g (DGraph&) - the graph we will add the edge to. */
	int a, b, c;
	cout << "v-v-c \n";
	cin >> a >> b >> c;
	g.addEdge(a, b);
}

string chooseFileG() {
	/*	Choose a file to initialize the costless graph. 
			Output: (string) - the name of the file. */
	string cmd;

	cout << "\nChoose file: \n";
	cout << "1 - graph1k_nocost.txt \n";
	cout << "2 - graph10k_nocost.txt \n";
	cout << "3 - graph100k_nocost.txt \n";
	cout << "4 - graph1m.txt_nocost \n";

	while (1) {
		cin >> cmd;
		if (cmd.compare("1") == 0) {
			return "graph1k_nocost.txt";
		}
		else if (cmd.compare("2") == 0) {
			return "graph10k_nocost.txt";
		}
		else if (cmd.compare("3") == 0) {
			return "graph100k_nocost.txt";
		}
		else if (cmd.compare("4") == 0) {
			return "graph1m_nocost.txt";
		}
		else {
			cout << "Wrong file. \n";
		}
	}
}

string chooseFileGC() {
	/*	Choose a file to initialize the cost graph.
			Output: (string) - the name of the file. */
	string cmd;

	cout << "\nChoose file: \n";
	cout << "1 - graph1k.txt \n";
	cout << "2 - graph10k.txt \n";
	cout << "3 - graph100k.txt \n";
	cout << "4 - graph1m.txt \n";

	while (1) {
		cin >> cmd;
		if (cmd.compare("1") == 0) {
			return "graph1k.txt";
		}
		else if (cmd.compare("2") == 0) {
			return "graph10k.txt";
		}
		else if (cmd.compare("3") == 0) {
			return "graph100k.txt";
		}
		else if (cmd.compare("4") == 0) {
			return "graph1m.txt";
		}
		else {
			cout << "Wrong file. \n";
		}
	}
}



int chooseGraph() {
	/*	Choose a costless or a cost graph. 
			Output: 1 - for costless graphs
					2 - for cost graphs*/
	string cmd;
	while (1) {
		cout << "Choose the graph type: \n";
		cout << "[1] Graph without costs. \n";
		cout << "[2] Graph with costs. \n";
		cin >> cmd;
		if (cmd == "1") return 1;
		else if (cmd == "2") return 2;
		else {
			cout << "Wrong graph type. \n";
			cout << "Enter 1 or 2 \n";
		}
	}

}

DGraph initializeG() {
	/*	Initialize the costless graph. 
			Output: (DGraph) - the initialized graph. */
	ifstream f;
	int n, m, i;
	int a, b;
	string file;

	file = chooseFileG();
	f.open(file);
	f >> n;
	f >> m;
	cout << "n = " << n << "\n";
	cout << "m = " << m << "\n";
	DGraph g = DGraph{ n };

	for (i = 0; i<m; i++) {
		f >> a >> b;
		g.addEdge(a, b);
	}
	return g;
}

DGraphCost initializeGC() {
	/*	Initialize the cost graph.
			Output: (DGraph) - the initialized graph. */
	ifstream f;
	int n, m, i;
	int a, b, c;
	string file;

	file = chooseFileGC();
	f.open(file);
	f >> n;
	f >> m;
	cout << "n = " << n << "\n";
	cout << "m = " << m << "\n";
	DGraphCost g = DGraphCost{ n };

	for (i = 0; i<m; i++) {
		f >> a >> b >> c;
		g.addEdge(a, b, c);
	}
	return g;
}

void menuCommandsG() {
	/* Commands for the costless graph menu. */
	cout << "+---------------+ \n";
	cout << "| Menu commands | \n";
	cout << "+---------------+ \n";
	cout << " add - add edge \n";
	cout << " in  - get in-degree \n";
	cout << " out - get out-degree \n";
	cout << " nov - no. of vertices \n";
	cout << " noe - no. of edges \n";
	cout << " ise - is edge? \n";
	cout << " x  - exit \n";
}
void menuCommandsGC() {
	/* Commands for the cost graph menu. */
	cout << "+---------------+ \n";
	cout << "| Menu commands | \n";
	cout << "+---------------+ \n";
	cout << " add - add edge \n";
	cout << " in  - get in-degree \n";
	cout << " out - get out-degree \n";
	cout << " nov - no. of vertices \n";
	cout << " noe - no. of edges \n";
	cout << " ise - is edge? \n";
	cout << " gco - get the cost of an edge\n";
	cout << " sco - set the cost of an endge\n";
	cout << " x  - exit \n";
}

int executeCommandG(string cmd, DGraph& g) {
	/*	Execute the given command on the given costless graph. 
			Input:	cmd (string) - the command
					g (DGraph&) - the costless graph. 
			Output: 1 - for command 'x'
					0 - otherwise. */
	if (cmd.compare("x") == 0) {
		cout << ">> Exit \n";
		cout << "\n";
		return 1;
	}
	else if (cmd.compare("add") == 0) {
		cout << ">> Add edge \n";
		readEdgeG(g);
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("in") == 0) {
		int x;
		cout << ">> Get in-degree \n";
		cout << "v = ";
		cin >> x;
		cout << "in-degree(" << x << ") = " << g.getInDegree(x);
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("out") == 0) {
		int x;
		cout << ">> Get out-degree \n";
		cout << "v = ";
		cin >> x;
		cout << "out-degree(" << x << ") = " << g.getOutDegree(x);
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("nov") == 0) {
		cout << ">> No. of vertices \n";
		cout << g.getNoOfVertices() << "\n";
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("noe") == 0) {
		cout << ">> No. of edges \n";
		cout << g.getNoOfEdges() << "\n";
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("ise") == 0) {
		int v1, v2, ok;
		cout << ">> Is edge? \n";
		cout << "v1 = ";
		cin >> v1;
		cout << "v2 = ";
		cin >> v2;
		ok = g.isEdge(v1, v2);
		if (ok == 0) {
			cout << "(" << v1 << ", " << v2 << ") is not an edge. \n";
		}
		else {
			cout << "(" << v1 << ", " << v2 << ") is an edge. \n";
		}
		cout << "\n";
		return 0;
	}
	else {
		cout << "> Wrong command. \n";
		cout << "\n";
		return 0;
	}
}
int executeCommandGC(string cmd, DGraphCost& g) {
	/*	Execute the given command on the given cost graph.
			Input:	cmd (string) - the command
					g (DGraph&) - the cost graph.
			Output: 1 - for command 'x'
					0 - otherwise. */
	if (cmd.compare("x") == 0) {
		cout << ">> Exit \n";
		cout << "\n";
		return 1;
	}
	else if (cmd.compare("add") == 0) {
		cout << ">> Add edge \n";
		readEdgeGC(g);
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("in") == 0) {
		int x;
		cout << ">> Get in-degree \n";
		cout << "v = ";
		cin >> x;
		cout << "in-degree(" << x << ") = " << g.getInDegree(x);
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("out") == 0) {
		int x;
		cout << ">> Get out-degree \n";
		cout << "v = ";
		cin >> x;
		cout << "out-degree(" << x << ") = " << g.getOutDegree(x);
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("nov") == 0) {
		cout << ">> No. of vertices \n";
		cout << g.getNoOfVertices() << "\n";
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("noe") == 0) {
		cout << ">> No. of edges \n";
		cout << g.getNoOfEdges() << "\n";
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("ise") == 0) {
		int v1, v2, ok;
		cout << ">> Is edge? \n";
		cout << "v1 = ";
		cin >> v1;
		cout << "v2 = ";
		cin >> v2;
		ok = g.isEdge(v1, v2);
		if (ok == 0) {
			cout << "(" << v1 << ", " << v2 << ") is not an edge. \n";
		}
		else {
			cout << "(" << v1 << ", " << v2 << ") is an edge. \n";
		}
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("gco") == 0) {
		int v1, v2, cost, ise;
		cout << ">> Get cost \n";
		cout << "v1 = ";
		cin >> v1;
		cout << "v2 = ";
		cin >> v2;

		ise = g.isEdge(v1, v2);

		if (ise == 0) {
			cout << "No edge from " << v1 << " to " << v2 << "\n";
		}
		else {
			cost = g.getCost(make_pair(v1, v2));
			cout << "cost(" << v1 << ", " << v2 << ") = " << cost << "\n";
		}
		cout << "\n";
		return 0;
	}
	else if (cmd.compare("sco") == 0) {
		int v1, v2, cost, ise;
		cout << ">> Set cost \n";
		cout << "v1 = ";
		cin >> v1;
		cout << "v2 = ";
		cin >> v2;

		ise = g.isEdge(v1, v2);
		if (ise == 0) {
			cout << "No edge from " << v1 << " to " << v2 << "\n";
		}
		else {
			cout << "cost = ";
			cin >> cost;
			g.setCost(make_pair(v1, v2), cost);
		}
		cout << "\n";
		return 0;
	}
	else {
		cout << "> Wrong command. \n";
		cout << "\n";
		return 0;
	}
}

void mainMenu() {
	/* The main menu. Here we put all the other menus together. */
	string cmd;
	int gtype;
	DGraph g;
	DGraphCost gc;

	cout << ">> Initialize graph\n";
	gtype = chooseGraph();
	if (gtype == 1) {
		DGraph g = initializeG();
		menuCommandsG();
		do {
			cout << "Enter command: \n> ";
			cin >> cmd;
		} while (!executeCommandG(cmd, g));
	}
	else if (gtype == 2) {
		DGraphCost gc = initializeGC();
		menuCommandsGC();
		do {
			cout << "Enter command: \n> ";
			cin >> cmd;
		} while (!executeCommandGC(cmd, gc));
	}

}

int main()
{
	mainMenu();

	return 0;
}