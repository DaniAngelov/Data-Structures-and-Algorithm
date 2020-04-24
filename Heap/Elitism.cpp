// github.com/DaniAngelov

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void printMedian(int* arr, int N)
{
    double median = arr[0];

    priority_queue<double> smaller;

    priority_queue< double, vector<double>, greater<double>> greater;

    smaller.push(arr[0]);

    cout << fixed;
    cout.precision(1);

    cout << median << endl;

    for (int i = 1; i < N; i++)
    {
        double x = arr[i];

        if (smaller.size() > greater.size())
        {
            if (x < median)
            {
                greater.push(smaller.top());
                smaller.pop();
                smaller.push(x);
            }
            else
            {
                greater.push(x);
            }

            median = (greater.top() + smaller.top()) / 2;
        }
        else if (smaller.size() == greater.size())
        {
            if (x < median)
            {
                smaller.push(x);
                median = smaller.top();
            }
            else
            {
                greater.push(x);
                median = greater.top();
            }
        }
        else
        {
            if (x > median)
            {
                smaller.push(greater.top());
                greater.pop();
                greater.push(x);
            }
            else
            {
                smaller.push(x);
            }

            median = (greater.top() + smaller.top()) / 2;
        }

        printf("%1.1f \n", median);

    }
}


int main()
{
    int N;
    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; i++)
    {

        scanf("%d", &arr[i]);
    }

    printMedian(arr, N);



    int _;
    cin >> _;
    return 0;
}
