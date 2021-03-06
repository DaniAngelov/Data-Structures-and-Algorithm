// github.com/DaniAngelov

#include <iostream>
#include <set>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

struct Point
{
public:

    double x;
    double y;
    


    Point(double x,double y)
    {
        this->x = x;
        this->y = y;
    }
    
    bool operator<(const Point& p)const
    {
        if (distance(*this) == distance(p))
        {
            return this->x < p.x;
        }
        
            return distance(*this) < distance(p);
        
    }

    double distance(const Point p)const
    {
        return p.x * p.x + p.y * p.y;
    }
};




int main()
{
    stack<Point> reversePoints;
    multiset<Point> s;
    
    int N,K;
    scanf("%d %d", &N, &K);

    priority_queue<Point> points;

    int x;
    int y;

    

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x , &y);
        
        Point p(x, y);
        points.push(p);

        if (points.size() > K)
            points.pop();
        
    }



    

    while (!points.empty())
    {
        reversePoints.push(points.top());
        points.pop();
    }

    while (!reversePoints.empty())
    {
        printf("%1.0f %1.0f \n", reversePoints.top().x, reversePoints.top().y);
        reversePoints.pop();
    }
    
    int _;
    cin >> _;
    return 0;
}
