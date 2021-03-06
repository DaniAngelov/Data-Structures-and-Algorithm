// github.com/DaniAngelov

#include <iostream>
#include <algorithm>
using namespace std;



long long SumCandiesCheck(long long* a, long long* b, long long candies, long long length)
{
    long long d = 0;

    for (int i = 0; i < length; i++)
    {
        if (b[i] != 0)
        {
            d += max(a[i] - candies / b[i], 0LL);
        }
    }
    return d;
}

long long binary_search(long long* a, long long* b, long long left, long long right, long long length, long long balloons)
{
    while (left < right)
    {
        long long mid = (left + right) / 2;
        long long balloons_required = SumCandiesCheck(a, b, mid, length);
        if(balloons_required <= balloons) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main()
{
    long long N;
    cin >> N;

    long long M;
    cin >> M;

    if (N == 0 || M == 0)
    {
        cout << "0";
        return 0;
    }


    long long* balloons = new long long[N];

    long long* candies = new long long[N];

    for (int i = 0; i < N; i++)
    {
        cin >> balloons[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> candies[i];
    }

    long long max_candies = 0;

    for (int i = 0; i < N; i++)
    {
        max_candies = max(balloons[i] * candies[i], max_candies);
    }

    cout << binary_search(balloons, candies, 0, max_candies, N, M);


    int _;
    cin >> _;
    return 0;
}
