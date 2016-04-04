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
	DGraph(int n=10);
	DGraph(const DGraph &g);
	/* DESTRUCTOR */
	~DGraph();

	/* GETTERS */
	int getNoOfVertices();
	int getNoOfEdges();
	int getInDegree(int x);
	int getOutDegree(int x);
	vector<int> getInbounds(int x);
	vector<int> getOutbounds(int x);

	/* ADD */
	void addEdge(int x, int y);
	bool isEdge(int x, int y);

	/* ITERATORS */
	vector<int> iteratorIn(int x);
	vector<int>::iterator iteratorInBegin(int x);
	vector<int>::iterator iteratorInEnd(int x);
	vector<int>::iterator iteratorOutBegin(int x);
	vector<int>::iterator iteratorOutEnd(int x);

};

/* CONSTRUCTORS [DGraph]*/
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

/* DESTRUCTOR [DGraph]*/
DGraph::~DGraph() {
}

/* GETTERS [DGraph]*/
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

/* ADD [DGraph]*/
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

/* ITERATORS [DGraph]*/
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
	DGraphCost(int n=10);
	DGraphCost(const DGraphCost& g);
	~DGraphCost();

	/* GETTERS */
	int getCost(pair<int, int> edge);
	map<pair<int, int>, int> getCosts();

	/* SETTERS */
	void setCost(pair<int, int> edge, int cost);

	/* OPERATIONS */
	void addEdge(int x, int y, int z);
};

/* CONSTRUCTORS [DGraphCost] */
DGraphCost::DGraphCost(int n): DGraph(n) {
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
void readEdge(DGraph &g) {
	int a, b, c;
	cout << "v-v-c \n";
	cin >> a >> b >> c;
	g.addEdge(a, b);
}

string chooseFileG() {
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

string chooseFileGC() {
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


int chooseGraph() {
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
	if (cmd.compare("x") == 0) {
		cout << ">> Exit \n";
		cout << "\n";
		return 1;
	}
	else if (cmd.compare("add") == 0) {
		cout << ">> Add edge \n";
		readEdge(g);
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
	if (cmd.compare("x") == 0) {
		cout << ">> Exit \n";
		cout << "\n";
		return 1;
	}
	else if (cmd.compare("add") == 0) {
		cout << ">> Add edge \n";
		readEdge(g);
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

void run() {
	//    readEdge(g);

	//    g.addEdge(0, 0, 1);
	//    g.addEdge(0, 1, 2);
	//    g.addEdge(0, 2, 3);
	//    g.addEdge(1, 0, 4);
	//    g.addEdge(1, 1, 5);
	//    g.addEdge(1, 2, 6);
	//    g.addEdge(1, 3, 7);
	//    cout<<"No. of vertices:     "<<g.getNoOfVertices()<<"\n";
	//    cout<<"No. of edges:        "<<g.getNoOfEdges()<<"\n";
	//    cout<<"isEdge(0, 0):        "<<g.isEdge(0, 0)<<"\n";
	//    cout<<"getInDegree(0):      "<<g.getInDegree(0)<<"\n";
	//    cout<<"getOutDegree(0):     "<<g.getOutDegree(0)<<"\n";
	//    cout<<"getCost(<0,0>):      "<<g.getCost(make_pair(0,0))<<"\n";
	//    cout<<"setCost(<0,0>, 10):  "<<"\n"; g.setCost(make_pair(0,0), 10);
	//    cout<<"cost(<0,0>):         "<<g.getCost(make_pair(0,0))<<"\n";

	//    vector<int>::iterator it;
	//    vector<int> v;
}

int main()
{

	mainMenu();


	return 0;
}
