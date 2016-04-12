#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "DGraphCost.h"

using namespace std;

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