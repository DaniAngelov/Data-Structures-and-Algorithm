// github.com/DaniAngelov

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


 int counter = 0;

struct Edge
{
  int from;
    int to;
    int weight;
    
    bool operator<(const Edge& rhs)
    {
        return weight < rhs.weight;
    }
};


vector<Edge> findAllEdges( vector<int> from,vector<int> to ,vector<int> weight)
{
    vector<Edge> edges;
    
    for(int i =0;i < from.size();i++ )
    {
        edges.push_back(Edge{from[i],to[i],weight[i]});
    }
    return edges;
}

int kruskal(int M, vector<int> from,vector<int> to ,vector<int> weight)
{
    if(M < 1)
        return 0;
    
    vector<Edge> AllEdges = findAllEdges(from,to,weight);
    
    sort(AllEdges.begin(),AllEdges.end());
    
    vector<int> elements;
    elements.resize(M + 1);
    
    for (int i = 0; i < M + 1; i++)
    {
        elements[i] = i;
    }

   

    for (auto edge : AllEdges)
    {
        if (elements[edge.from] !=elements[edge.to])
        {
            counter += edge.weight;
            int oldEdge = elements[edge.from];
            int newEdge = elements[edge.to];

            for (int i = 0; i < elements.size(); i++)
            {
                if (elements[i] == oldEdge)
                {
                    elements[i] = newEdge;
                }
            }
        }
    }

    return counter;
}

int main()
{
    
    int N;
    cin >> N;

    int M;
    cin >> M ;

    vector<int> graphFrom;
    vector<int> graphTo;
    vector<int> graphWeight;

    int from,to,weight;
    
    for (int i = 0; i < M; i++)
    {
        
        cin >> from >> to >> weight;

        graphFrom.push_back(from);
       graphTo.push_back(to);
        graphWeight.push_back(weight);
    }

    cout << kruskal(N,graphFrom,graphTo, graphWeight);

    
    
    int _;
    cin >> _;
    return 0;
}
