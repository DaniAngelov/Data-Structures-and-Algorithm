// github.com/DaniAngelov

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

unordered_map<int, int> discos_m;
vector<int> offers_vec;


struct Pair {
    int index;
    int distance;

    bool operator<(const Pair & rhs) const {
        return distance > rhs.distance;
    }

    
};

struct Edge {
    int from;
    int to;
    int weight;
};

struct Node {
    list<Pair> neighbours;

    bool hasNeighbour(int index) {
        for (auto neighbour : neighbours)
        {
            if (neighbour.index == index)
            {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int index, int distance)
    {
        neighbours.push_back(Pair{ index, distance });
    }
};

class Graph {
private:
    vector<Node> nodes;

public:
    Graph(int nodeCount = 0) 
    {
        nodes.resize(nodeCount);
    }

    void connect(int from, int to, int distance) 
    {
        
            nodes[from].addNeighbour(to, distance);
            nodes[to].addNeighbour(from, distance);
        
    }

    void dijkstra(int start)
        
    {
        if (nodes.size() < 1)
            return;


        vector<int> distance(nodes.size(), INT_MAX);

        vector<bool> visited(nodes.size(), false);

        distance[start] = 0;

        priority_queue<Pair> next;
        next.push({ start, 0 });
        while (!next.empty()) {
            Pair currPair = next.top();
            next.pop();
            int curr = currPair.index;


            if (visited[curr]) 
            {
                continue;
            }
            visited[curr] = true;

            if (discos_m[curr] > currPair.distance && curr != start)
            {
                discos_m[curr] = currPair.distance;
            }

            for (auto neighbour : nodes[curr].neighbours)
            {
                int neighbourNode = neighbour.index;
                int NewDistance = distance[curr] + neighbour.distance;
                if (NewDistance < distance[neighbourNode])
                {
                    distance[neighbourNode] = NewDistance;
                    next.push({ neighbourNode, NewDistance });
                }
            }
            
        }


    

    }
};

int main()
{

    int N;
    cin >> N;
    int M;
    cin >> M;

    Graph g(N + 1);

    for (int i = 0; i < M; i++)
    {
        int object;
        int object2;
        int distance;
        cin >> object >> object2 >> distance;

        g.connect(object, object2, distance);

    }



    int discos;
    cin >> discos;

    int* disco_number = new int[discos];

    for (int i = 0; i < discos; i++)
    {

        cin >> disco_number[i];
        g.connect(N, disco_number[i], 0);
        discos_m.insert({ disco_number[i],INT_MAX });
        
    }

    
    
    int offers;
    cin >> offers;

    for (int i = 0; i < offers; i++)
    {

        int number;
        cin >> number;
        offers_vec.push_back(number);

        discos_m.insert({ number,INT_MAX });

    }
    

    g.dijkstra(N);
    
    for (int i = 0; i < offers; i++)
    {

        cout << discos_m[offers_vec[i]] << endl;
    }

    int _;
    cin >> _;
    return 0;
}
