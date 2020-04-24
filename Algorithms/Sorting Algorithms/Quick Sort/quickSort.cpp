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


void quickSort(int* arr, int low, int high)
{

	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}



int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];		

	}

	quickSort(arr, 0, n - 1);

	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";

	}


	int _;
	cin >> _;
	return 0;
}

