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
	~IntegerSetArray();
	bool insert(int x);
	bool search(int x) const;
	void remove(int x);
};

bool IntegerSetArray::insert(int x)
{
	printf("SIZE = %d, NUM ITEMS = %d",size, numItems);
    if(numItems+1 > size)
		return false;
    array[numItems] = x;
    numItems += 1;
	return true;
}

bool IntegerSetArray::search(int x) const

{
	for(int i = 0; i < size; i++)
	{
		if(array[i] == x)
		{
			return true;
		}
	}
	return false;
}

void IntegerSetArray::remove(int x)
{
	int* newArr = new int[size];
	int count = 0;
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

IntegerSetArray::~IntegerSetArray()
{
	delete[] array;
}
