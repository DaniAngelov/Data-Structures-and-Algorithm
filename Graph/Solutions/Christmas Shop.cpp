// github.com/DaniAngelov

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
unordered_map<int,string> m2;
vector<int> vec;



struct Node
{
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

class Graph
{
private:
    vector<Node> nodes;
    bool check = false;

    void _DFS(int current, vector<bool>& visited, int start)
    {

        if (check)
        {
            return;
        }

        visited[current] = true;
        vec.push_back(current);

        for (auto i : nodes[current].neighbours)
        {

            if (!visited[i])
            {

                _DFS(i, visited, start);

            }
            else if (i == start && !check)
            {
                vec.push_back(start);
                check = true;

            }

        }

        if (!check)
        {
            vec.pop_back();
        }




    }




public:
    Graph(int nodeCount = 0) {
        nodes.resize(nodeCount);
    }


    void print() const
    {


        for (int node = 0; node < nodes.size(); node++) {
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

        }
    }



    void DFS(int start)
    {
        vector<bool> visited;
        visited.resize(nodes.size(), false);


        _DFS(start, visited, start);



    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;

    int M;
    cin >> M;

    string city1;
    string city2;
    string searched;
    int number = 0;


    Graph g(M + 1);

    for (int i = 0; i < M; i++)
    {
        cin >> city1 >> city2;



        if (!m.count(city1))
        {
            m.insert({ city1, number });
            m2.insert({ number++,city1 });
        }
        if (!m.count(city2))
        {
            m.insert({ city2,number });
            m2.insert({ number++,city2 });
        }


        unordered_map<string, int>::iterator it;
        unordered_map<string, int>::iterator it2;
        it = m.find(city1);
        it2 = m.find(city2);
        g.connect(it->second, it2->second);



    }

    unordered_map<string, int>::iterator it;


    cin >> searched;

    it = m.find(searched);


    g.DFS(it->second);


    for (int i = 0; i < vec.size(); i++)
    {
        cout << m2[vec[i]] << " ";

    }
    if (vec.empty())
    {
        cout << "-1" << endl;
    }





    int _;
    cin >> _;
    return 0;
}
