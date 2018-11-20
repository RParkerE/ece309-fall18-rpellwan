#include "MinHeap.h"
#include <stdio.h>

void MinHeap::heapify(int *heap, int i, int n)
{
	int j, temp;
	temp = heap[i];
	j = 2 * i;
	while(j <= n)
	{
		if(j < n && heap[j+1] < heap[j])
			j = j + 1;
		if(temp < heap[j])
			break;
		else if(temp >= heap[j])
		{
			heap[j/2] = heap[j];
			j = 2 * j;
		}
	}
	heap[j/2] = temp;
	return;
}

void MinHeap::builder(int *heap, int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
	{
		heapify(heap,i,n);
	}
}

MinHeap::MinHeap(int hsize = 10)
{
	heap = new int[hsize];
	size = hsize;
	elements = 0;
	builder(heap, size);
}

bool MinHeap::add(int data)
{
	if (elements >= size)
		return false;

	heap[elements++] = data;
	builder(heap, size);
	return true;
}

void MinHeap::remove()
{
	for (int j = 0; j < elements; j++)
	{
		heap[j] = heap[j + 1];
		
		elements--;
	}
	builder(heap, size);
}

int MinHeap::getVal(int index)
{
	if(index < elements)
		return heap[index];
	else
		return -1;
}
