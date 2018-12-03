#include <stdio.h>
#include <string>

using namespace std;

namespace ece309 {

class List {
private:
	class ListNode {
	private:
		string item; 
		ListNode *next;
	public:
		ListNode(string a) 
			{ item = a; next=NULL; }
		ListNode* getNext() { return next; }
		void setNext(ListNode *n) { next = n; }
		string getItem() { return item; }
	};
	ListNode *head;
	ListNode *tail;
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
	void push_back(string a)
	{
		ListNode *node = new ListNode(a);
		if (head==NULL) {  
			head = node;
			tail = node;
		} else {
			tail->setNext(node); 
			tail = node;         
		}
	}  
	bool remove_front(string &a)
	{
		if (!empty()) 
		{
			string copy = head->getItem(); 
			ListNode *tmp = head->getNext();
			delete head; 
			head = tmp;  
			if (tmp==NULL) 
				tail = NULL;
			return true;
		}
		return false; 
	}   
	bool empty()
	{
		return head==NULL;
	}
	string get(int n)
	{
		int i = 0;
		ListNode* currNode = head;
		
		while (currNode != NULL)
		{
			if (i == n)
				return currNode->getItem();		
			i++;
			currNode = currNode->getNext();
		}
		
		return "";
	}
	int length()
	{
		int i = 0;
		ListNode* currNode = head;
		
		while (currNode != NULL)
		{
			++i;
			currNode = currNode->getNext();
		}
		return i;
	}
	~List()
	{
		string t;
		while(!empty()) 
			remove_front(t);   
	}
};

}