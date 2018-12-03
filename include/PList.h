#ifndef PLIST_H
#define PLIST_H

#include <stdio.h>
#include "Object.h"

namespace ece309 {

class List {
private:
	class ListNode {
	private:
		Object obj; 
		ListNode *next;
	public:
		ListNode(Object a) 
			{ obj = a; next=NULL; }
		ListNode* getNext() { return next; }
		void setNext(ListNode *n) { next = n; }
		Object getItem() { return obj; }
	};
	ListNode *head;
	ListNode *tail;
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
	void push_back(Object a)
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
	bool remove_front(Object &a)
	{
		if (!empty()) 
		{ 
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
	Object get(int n)
	{
		int i = 0;
		Object o;
		ListNode* currNode = head;

		while (currNode != NULL)
		{
			if (i == n)
				return currNode->getItem();		
			i++;
			currNode = currNode->getNext();
		}
		
		return o;
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
		Object t;
		while(!empty()) 
			remove_front(t);   
	}
};

}

#endif //PLIST_H
