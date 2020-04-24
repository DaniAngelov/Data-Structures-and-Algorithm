// github.com/DaniAngelov

#include <iostream>
#include <queue>
using namespace std;




int counter = 0;



struct Node
{

    int x, y;
    int step = 0;
    
    Node()
    {
        this->x = 0;
        this->y = 0;
    }
    Node(int x ,int y)
    {
        this->x = x;
        this->y = y;
    }
};





void Maze(int N,int M,char** matrix,bool** visited,Node* start,Node* destination)
{
    queue<Node*> q;

    q.push(start);

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if (curr->x == destination->x && curr->y == destination->y)
        {
            cout << curr->step << endl;
            return;
        }

        for (int i = 1; i < N && matrix[curr->x + i][curr->y] != '#' ;  i++)
        {
            if (i == 1 && matrix[curr->x + 1][curr->y] != '#')
            {
                Node* temp = new Node();
                temp->x = curr->x + 1;
                temp->y = curr->y;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
            }
            else if(i + curr->x <= N && matrix[curr->x + i + 1][curr->y] == '#')
            {
                Node* temp = new Node();
                temp->x = curr->x + i;
                temp->y = curr->y;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
                break;
            }
        }
        for (int i = 1; i < N  && matrix[curr->x - i][curr->y] != '#'; i++)
        {
            if (i == 1 && matrix[curr->x - 1][curr->y] != '#')
            {
                Node* temp = new Node();
                temp->x = curr->x - 1;
                temp->y = curr->y;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
            }
            else if (curr->x - i > 0 && matrix[curr->x - i - 1][curr->y] == '#')
            {
                Node* temp = new Node();
                temp->x = curr->x - i;
                temp->y = curr->y;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
                break;
            }
        }
        for (int i = 1; i < M  && matrix[curr->x][curr->y + i] != '#'; i++)
        {
            if (i == 1 && matrix[curr->x ][curr->y + 1] != '#')
            {
                Node* temp = new Node();
                temp->x = curr->x;
                temp->y = curr->y + 1;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
            
            }
            else if (i + curr->y <= M && matrix[curr->x][curr->y + i + 1] == '#')
            {
                Node* temp = new Node();
                temp->x = curr->x;
                temp->y = curr->y + i;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
                
                break;
            }
        }
        for (int i = 1; i <= M  && matrix[curr->x][curr->y - i] != '#'; i++)
        {
            if (i == 1 && matrix[curr->x][curr->y - 1] != '#')
            {
                Node* temp = new Node();
                temp->x = curr->x;
                temp->y = curr->y - 1;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
                
            }
            else if (curr->y - i > 0 && matrix[curr->x][curr->y - i - 1] == '#')
            {
                Node* temp = new Node();
                temp->x = curr->x;
                temp->y = curr->y - i ;
                temp->step = curr->step + 1;
                if (!visited[temp->x][temp->y])
                {
                    q.push(temp);
                    visited[temp->x][temp->y] = true;
                }
                break;
            }
        }


    }
    cout << "-1" << endl;
}


int main()
{

    int N;
    cin >> N;
    
    int M;
    cin >> M;

    Node* start = new Node();
    Node* destination = new Node();

    char** arr = new char*[N];
    bool** visited = new bool*[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool[M];
        arr[i] = new char[M];
    }

    int number = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            Node* cur = new Node(i, j);
            
            
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                start->x = i;
                start->y = j;
            }
            if (arr[i][j] == 'F')
            {
                destination->x = i;
                destination->y = j;
            }
        

        }

    }


    Maze(N, M, arr, visited, start, destination);




    int _;
    cin >> _;

    return 0;
}
