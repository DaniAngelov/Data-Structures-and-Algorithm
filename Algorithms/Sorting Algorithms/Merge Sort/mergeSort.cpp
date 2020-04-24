// github.com/DaniAngelov

#include <iostream>
using namespace std;


void merge(int* arr, int start, int mid, int end)		// we sort and merge two sorted arrays after
{
	int length1 = mid - start + 1;
	int length2 = end - mid;

	int* arr1 = new int[length1];
	int* arr2 = new int[length2];		


	for (int i = 0; i < length1; i++)
	{
		arr1[i] = arr[start + i];				// declare elements of first array
	}

	for (int i = 0; i < length2; i++)
	{
		arr2[i] = arr[mid + 1 + i];				// declare elements of second array
	}

	int i = 0;
	int j = 0;
	int k = start;



	while (i < length1 && j < length2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < length1)			// for remaining unsorted elements
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while (j < length2)			// for remaining unsorted elements
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
}
void mergeSort(int* arr, int start, int end)		//merge sort function
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}
}


int main()
{

	int N;
	cin >> N;
	

	int* arr = new  int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];					//input
	}


	mergeSort(arr, 0, N - 1);			

	
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";			// output
	}


	int _;
	cin >> _;
	return 0;
}
