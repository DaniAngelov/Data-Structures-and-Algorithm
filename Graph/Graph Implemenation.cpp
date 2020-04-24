// github.com/DaniAngelov

#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

struct Pair
{
	int index;
	string name;
};

struct Node {
	
	list<Pair> neighbours;

	bool hasNeighbour(int index)
	{
		for (auto i : neighbours)
		{
			if (i.index == index)
			{
				return true;
			}

		}
		return false;
	}

	void addNeighbour(int index, string name)
	{
		neighbours.push_back(Pair{ index,name});
	}
};

class Graph {
private:
	vector<Node> nodes;

public:
	Graph(int nodesCount = 0)
	{
		nodes.resize(nodesCount);
	}

	void print()
	{
		for (int node = 0; node < nodes.size(); node++)
		{
			cout << node << ": ";
			for (auto i : nodes[node].neighbours)
			{
				cout << i.index << "(" << i.name << "),";
			}
			cout << endl;
		}
	}

	void connect(int from, int to, string weight)
	{
		if (!nodes[from].hasNeighbour(to))
		{
			nodes[from].addNeighbour(to,weight);
			
		}
	}

};

int main() {
	Graph g(11);
	g.connect(0, 1, "a");
	g.connect(1, 0 , "b");
	g.connect(1, 2 , "c");
	g.connect(1, 3 , "d");
	g.connect(2, 1 , "f");
	g.connect(3, 1 , "g");
	g.connect(3, 2 , "h");
	g.connect(3, 10 , "j");
	g.connect(10, 2 , "k");

	g.print();


	int _;
	cin >> _;
	return 0;
}

