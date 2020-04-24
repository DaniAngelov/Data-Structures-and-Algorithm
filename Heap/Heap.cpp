// github.com/DaniAngelov

#include <iostream>
#include <vector>
using namespace std;
#include <queue>


class minHeap
{
	int heapSize;
	int* heap = new int[50000];

	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return i * 2 + 1; }
	int right(int i) { return i * 2 + 2; }

	bool hasLeft(int i) { return i * 2 + 1 < heapSize; }
	bool hasRight(int i) { return i * 2 + 2 < heapSize; }

	void pullUp(int index)
	{
		if (index == 0)
			return;

		if (heap[index] < heap[parent(index)])
		{
			swap(heap[index], heap[parent(index)]);
			pullUp(parent(index));
		}
	}

	void heapify(int index)
	{
		int minValueChild = left(index);

		if (hasRight(index) && heap[left(index)] > heap[right(index)])
		{
			minValueChild = right(index);
		}

		if (hasLeft(index) && heap[minValueChild] < heap[index])
		{
			swap(heap[minValueChild], heap[index]);
			heapify(minValueChild);
		}
	}

public:

	
	minHeap()
	{
		heapSize = 0;
	}
	int getSize()
	{
		return this->heapSize;
	}
	void push(int value)
	{
		heapSize++;
		heap[heapSize - 1] = value;
		pullUp(heapSize - 1);
	}
	void pop()
	{
		swap(heap[0], heap[--heapSize]);
		heapify(0);
	}
	
	 int top()
	{
		return heap[0];
	}

	
};


int main()
{
	minHeap heap;
	heap.push(1);
	heap.push(5);
	heap.push(2);
	heap.pop();
	heap.push(12);
	heap.push(7);
	heap.push(30);

	int size = heap.getSize();

	for (int i = 0; i < size; i++)
	{
		cout << heap.top() << " ";
		heap.pop();
	}

	int _;
	cin >> _;
	return 0;
}
