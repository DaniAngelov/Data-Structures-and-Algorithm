// github.com/DaniAngelov

#include <iostream>
#include <string> 
using namespace std;


int partition(int *arr, int low, int high)
{

    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] <= arr[high])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
};


void Sort(int* arr, int low, int high)
{

    if (low < high)
    {
        int pi = partition(arr, low, high);
        Sort(arr, low, pi - 1);
        Sort(arr,pi + 1, high);
    }
}




int counter = 0;

int minPushes(int n, int x, int* arr)
{

    

    for (int i = n - 1; i >= 0; i--)
    {
        
        if (i == 0)
        {
            
            if (arr[i] - x > 0)
            {
                
                return n;
                
            }
        }

        if (arr[i] > 0)
        {
            if (arr[i - 1] - x > 0)
            {
                counter++;

                for (int j = 0; j < i; j++)
                {
                    arr[j] -= x;
                }
            }
            else
            {
                counter++;
                return counter;
            }
        }
        else
        {
            counter++;
            return counter;
        }

    }

    return n;


}
    


int removeDuplicates(int arr[], int n)
{

    if (n == 0 || n == 1)
        return n;

    int* newArr = new int[n];


    int j = 0;

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i] != arr[i + 1])
        {
            newArr[j++] = arr[i];
        }
    }
    
    newArr[j++] = arr[n - 1];

    
    for (int i = 0; i < j; i++)
        arr[i] = newArr[i];

    return j;
}


int main()
{
    int n;
    cin >> n;
    
    int x;
    cin >> x;
    





    int* arr = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

    }

    Sort(arr, 0, n - 1);

    n = removeDuplicates(arr, n);

    
    cout << minPushes(n, x, arr);
    
    

    int _;
    cin >> _;
    return 0;
}
