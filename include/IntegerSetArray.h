#ifndef INTEGERSETARRAY_H
#define INTEGERSETARRAY_H

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}  
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

class IntegerSetArray : public IntegerSet {
private:
	int numItems;
	int size;
	int* array;
public:
	IntegerSetArray(int htsize):IntegerSet(htsize)
	{
		array = new int[htsize];
		for(int i = 0; i < htsize; i++)
			array[i] = -1;
		size = htsize;
		numItems = 0;
	}
	~IntegerSetArray()
	{
		delete[] array;
	}
	bool insert(int x)
	{
		printf("SIZE = %d, NUM ITEMS = %d",size, numItems);
		if(numItems+1 > size)
			return false;
		array[numItems] = x;
		numItems += 1;
		return true;
	}
	bool search(int x) const
	{
		int pos;
		for(int i = 0; i < size; i++)
		{
			if(array[i] == x)
			{
				pos = i;
				return true;
			}
		}
		return false;
	}
	void remove(int x)
	{
		int* newArr = new int[size];
		int count = 0; int current = 0;
		for(int i = 0; i < size; i++)
		{
			if(array[i] == x)
				count += 1;
		
			else
				newArr[i - count] = array[i];
		}
		delete[] array;
		array = newArr;
		numItems -= count;
	}
};

#endif //INTEGERSETARRAY_H
