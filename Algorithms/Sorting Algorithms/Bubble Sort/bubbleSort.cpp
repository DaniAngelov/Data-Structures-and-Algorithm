// github.com/DaniAngelov

#include <iostream>
using namespace std;


void bubbleSort(int* arr,int N)
{

	for (int i = 0; i < N; i++)	
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[i] < arr[j])			
				swap(arr[i], arr[j]);
		}
	}
}

int main()
{
	int N;		        //length
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];		      //input
	}
	
	bubbleSort(arr,N);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";		    //output
	}
	

	int _;
	cin >> _;
	return 0;
}
