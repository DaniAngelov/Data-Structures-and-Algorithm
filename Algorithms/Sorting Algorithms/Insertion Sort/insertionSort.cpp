// github.com/DaniAngelov

#include <iostream>
using namespace std;

void insertionSort(int* arr, int n)
{
	int a;
	int b;
	int key;
	for (a = 1; a < n; a++)
	{
		key = arr[a];
		b = a - 1;

		while (b >= 0 && arr[b] > key)
		{
			arr[b + 1] = arr[b];
			b = b - 1;
		}
		arr[b + 1] = key;
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

	insertionSort(arr, N);      // Time complexity : O(N^2) , Space complexity : O(1)
	

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}


	int _;
	cin >> _;
	return 0;
}
