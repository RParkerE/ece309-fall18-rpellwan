#include <stdio.h>
#include <string>

using namespace std;

class StringArrayList{
private:
	string *arrList = NULL;
	int firstIdx;
	int lastIdx;
public:
    StringArrayList(int size = 1) 
	{ 
		arrList = new string[size];
		firstIdx = 0;
		lastIdx = size - 1;
	}
	bool push_back(string s)
	{
		for(int i = 0; i <= lastIdx; i++)
		{
			if(arrList[i].empty())
			{
				arrList[i] = s;
				return true;
			}
		}
		lastIdx = lastIdx + 1;
		int newSize = lastIdx + 1;
		string *tmpList = new string[newSize];
		tmpList[lastIdx] = s;
		for(int n = 0; n <= lastIdx; n++)
		{
			if(tmpList[n].empty())
			{
				tmpList[n] = arrList[n];
			}
		}
		arrList = new string[newSize];
		arrList = tmpList;
		return true;
	}
	string get(int n)
	{
		return arrList[n];
	}
	int length()
	{
		return lastIdx + 1;
	}
	string remove_front()
	{
		string s;
		string *tmpList = new string[lastIdx];
		for(int i = 0; i <= lastIdx; i++)
		{
			if(i == 0)
				s = arrList[i];
			else
				tmpList[i-1] = arrList[i];
		}
		arrList = new string[lastIdx];
		arrList = tmpList;
		return s;
	}
	~StringArrayList()
	{
		delete[] arrList;
	}
};
