// github.com/DaniAngelov

#include <iostream>
using namespace std;



void selectionSort(int arr[], int n)
{
	int i;
	int j;
	int min;

	
	for (i = 0; i < n - 1; i++)
	{
		 
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;

		
		swap(arr[min], arr[i]);
	}
}



int main()
{
	int N;
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	selectionSort(arr, N);            // Time complexity: O(N^2) , Space complexity: O(1)
	
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}


	

	int _;
	cin >> _;
	return 0;
}



