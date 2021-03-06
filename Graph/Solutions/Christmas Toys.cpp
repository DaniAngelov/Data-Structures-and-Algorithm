// github.com/DaniAngelov

#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

map<int, int> m;
set<int> s;
int counter = 0;

struct Node {
    list<int> neighbours;

    bool hasNeighbour(int index) {
        for (auto i : neighbours) {
            if (i == index) {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int index) {
        neighbours.push_back(index);
    }
};

class Graph {
private:
    vector<Node> nodes;

    void _DFS(vector<bool> & visited, int current) {
        //cout << current << ", ";
        visited[current] = true;

        for (auto neighbour : nodes[current].neighbours) {
            if (!visited[neighbour]) {
                _DFS(visited , neighbour);
            }
        }
    }

public:
    Graph(int nodeCount = 0) {
        nodes.resize(nodeCount);
    }

    void print( ) const 
    {
        for (int node = 1; node < nodes.size(); node++) 
        {
            
            
            cout << node << ": ";
            for (auto neighbour : nodes[node].neighbours) 
            {
    
                cout << neighbour << ", ";
            }
            cout << "\n";
            
        }
    }

    void connect(int from, int to)
    {

        if (!nodes[from].hasNeighbour(to))
        {
            nodes[from].addNeighbour(to);


            nodes[to].addNeighbour(from);
        }



    }

    void Toys()
    {
        vector<bool> visited;

        visited.resize(nodes.size(), false);

        for (int i = 1; i < nodes.size(); i++)
        {
            if (!visited[i])
            {
                counter++;
                 _DFS(visited, i);
            }
        }
    }

    
    

};

int main() {

    int N;
    cin >> N;

    int M;
    cin >> M;
    Graph g(2 * M + 1);

    int* toy1 = new int[M];
    int* toy2 = new int[M];

    int number = 1;



    for (int i = 0; i < M; i++)
    {
        cin >> toy1[i] >> toy2[i];

        if (m.find(toy1[i]) == m.end())
        {
            m.insert({ toy1[i], number++ });
        }
        if (m.find(toy2[i]) == m.end())
        {
            m.insert({ toy2[i], number++ });
        }

        g.connect(m.at(toy1[i]), m.at(toy2[i]));

    }

    //g.print();
    g.Toys();

    cout << N - 2 * M + counter << endl;






    int x;
    cin >> x;
    return 0;
}
