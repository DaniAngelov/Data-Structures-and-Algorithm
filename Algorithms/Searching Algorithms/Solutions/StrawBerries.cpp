// github.com/DaniAngelov

#include <iostream>
#include <algorithm>
using namespace std;

int binary_search( long long* arr, long long  x, long long  left, long long  right, long long  length)
{
    
    
    if (left > right) return 0;

    int mid = (left + right) / 2;
    if (arr[mid] == x)
    {
        if (mid > length)
        {
            return 0;
        }
        return mid;
    }
    else
    {
        if (left == right)
        {
            if (x > arr[mid])
            {
                if (mid + 1 > length)
                {
                    return 0;
                }
                return mid + 1;
            }
            if (x < arr[mid])
            {
                if (mid > length)
                {
                    return 0;
                }
                return mid;
            }
        }
    }
    if (arr[mid] > x)
    {
        if (mid - 1 < left)
        {
            if (mid > length)
            {
                return 0;
            }
            return mid ;
        }
        return binary_search(arr, x, left, mid - 1,length);
    }
    if (arr[mid] < x)
    {
        if (mid + 1 > right)
        {
            if (mid + 1 > length)
            {
                return 0;
            }
            return mid + 1 ;
        }
        return binary_search(arr, x, mid + 1, right,length);
    }

    return 0;
}

int main()
{

    long long  n;
    cin >> n;
    
    if (n <= 0)
    {
        cout << 0;
        return 0;
    }
    long long* arr = new  long long[n + 1];

    arr[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] + arr[i - 1];

    }




    long long  m;
    cin >> m;

    if (m <= 0 || m > arr[n])
    {
        cout << 0;
        return 0;
    }

     long long* arr_berry = new long long[m];
     long long* arr_copy = new  long long[m];

    for (int i = 0; i < m; i++)
    {
        cin >> arr_berry[i];
        
        arr_copy[i] = binary_search(arr, arr_berry[i], 0, n , n);
    }

    for (int i = 0; i < m; i++)
    {
        cout << arr_copy[i] << endl;
    }




    // 2 7 3 4 9
    // 0 2 9 12 16 25

    int _;
    cin >> _;
    return 0;
}
