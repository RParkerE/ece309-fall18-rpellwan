#include <stdio.h>
#include <string>

using namespace std;

class StringArrayList{
private:
	string* arrList;
public:
	StringArrayList(int size=1)
	{
		arrList = new string[size];
	}
	void push_back(string s)
	{
		unsigned int i;
		for(i = 0; i < sizeof(arrList); i++)
		{
			if(arrList[i] ==  "")
				arrList[i] = s;
		}
		string* tmpArrList = new string[sizeof(arrList) + 1];
		tmpArrList = arrList;
		tmpArrList[-1] = s;
		delete[] arrList;
		arrList = new string[sizeof(tmpArrList)];
		arrList = tmpArrList;
		delete[] tmpArrList;
	}
	string get(int n)
	{
		unsigned int i = n;
		if(i > 0 && i < sizeof(arrList))
			return arrList[n];
		else
			return "";
	}
	int length()
	{
		return sizeof(arrList);
	}
	string remove_front(){
		unsigned int i;
		string tmp;
		tmp = arrList[0];
		for(i = 0; i < sizeof(arrList - 1); i++)
		{
			arrList[i] = arrList[i + 1];
		}
		return tmp;
	}
	~StringArrayList()
	{
		delete[] arrList;
	}
};
