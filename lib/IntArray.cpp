#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class IntArray 
{
    private:
        int numItems;
        int arrSize;
        int* array;
    public:
		IntArray(const char* str);
		IntArray(int size=1, int val=0);
		~IntArray();
		int& operator[](int index);
		IntArray* operator+=(const IntArray &rhs);
		IntArray operator+(const IntArray &rhs) const;
		IntArray operator-(const IntArray &rhs) const;
		IntArray operator*(int x) const;
		IntArray operator/(int x) const;
		IntArray operator<<(int count) const;
		operator char*() const;
		operator int() const;
		void set(int index, int val);
        void push_back(int x);
        int get(int n);
        int getLength();
        void remove_front();
        void print();

};

void IntArray::set(int index, int val) 
{
	array[index] = val;
}

void IntArray::push_back(int x)
{
    if(arrSize < numItems+1)
    {
        int newSize = arrSize*2;
        int* newArr = new int[newSize];
        memcpy(newArr, array, arrSize*sizeof(int));
        arrSize = newSize;
        delete[] array;
        array = newArr;
    }
    array[numItems] = x;
    numItems += 1;
}

int IntArray::get(int n)
{
    if (n<0 || n> numItems) 
    {
        cout<<"Please enter an index between 0 and "<< numItems << endl;
        return 0;
    }
    return array[n];
}

int IntArray::getLength()
{
    return numItems;
}

void IntArray::remove_front()
{
    if (numItems == 0) 
    {
        cout<<"Empty Array List..."<<endl;
        return;
    }
    
    for(int i = 0; i < numItems-1; i++)
    {
        array[i]=array[i+1];

    }
    array[numItems-1] = 0;
    numItems -= 1;
    
    
}

int& operator[](int index)
{
	return array[index];
}

IntArray* operator+=(const IntArray &rhs)
{	
    int i=0;
	
    for(i=0; i < arrSize && i < rhs.arrSize; i++)
		array[i] = array[i] + rhs.array[i];
	
	return this;
}

IntArray operator+(const IntArray &rhs) const
{
	IntArray result(arrSize);
	
    int i=0;
	
    for(i=0; i < arrSize && i < rhs.arrSize; i++)
		result.array[i] = array[i] + rhs.array[i];
	
	return result;
}

IntArray operator-(const IntArray &rhs) const
{
	IntArray result(arrSize);
	
    int i=0;
	
    for(i=0; i < arrSize && i < rhs.arrSize; i++)
		result.array[i] = array[i] - rhs.array[i];
	
	return result;
}

IntArray operator*(int x) const
{
	IntArray result(arrSize);
	
    int i=0;
	
    for(i=0; i < arrSize; i++)
		result.array[i] = array[i] * x;
	
	return result;
}

IntArray operator/(int x) const
{
	IntArray result(arrSize);
	
    int i=0;
	
    for(i=0; i < arrSize; i++)
		result.array[i] = array[i] / x;
	
	return result;
}

IntArray operator<<(int count) const
{
	IntArray result(arrSize);
	int c = count;
	
	while(c > 0)
	{
		result.array[count - c] = array[c];
		c -= 1;
	}
	for(int i = count; i < arrSize; i++)
		result.array[i] = array[i - count];
	
	return result;
}

operator char*() const
{
	char* arrStr = new char[arrSize];
	for(int i = 0; i < arrSize; i++)
	{
		if(array[i] > 0 && array[i] < 255)
			arrStr[i] = (char)array[i];
		else
			arrStr[i] = ' ';
	}
	
	return arrStr;
}

operator int() const
{
	int avg = 0;
	for(int i = 0; i < arrSize; i++)
	{
		avg += array[i];
	}
	avg = avg/2;
	
	return avg;
}

IntArray::IntArray(const char* str)
{
    int len = strlen(str);
	arrSize = len;
	array = new int[arrSize];
	numItems = 0;
	for(int i = 0; i < arrSize; i++)
	{
		array[i] = (int)str[i];
		numItems += 1;
	}
}

IntArray::IntArray(int size, int val)
{
    arrSize = size;
    array = new int[arrSize];
    numItems = 0;
	for(int i = 0; i < arrSize; i++)
	{
		array[i] = val;
		numItems += 1;
	}
}

IntArray::~IntArray()
{
    delete[] array;
}
