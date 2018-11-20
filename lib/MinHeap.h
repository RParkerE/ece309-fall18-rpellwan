#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>

class MinHeap {
private:
int *heap;
int size;
int elements;

void heapify(int *heap, int i, int n);
void builder(int *heap, int n);

public:
MinHeap(int hsize = 10);
bool add(int data);
void remove(int data);
int getVal(int index);
};

#endif // MINHEAP_H