#include <stdio.h>
#include "PList.h"
#include "Object.h"
#include "StringItem.h"
#include "DoubleItem.h"
#include "IntegerItem.h"

int main() {
	List l = List();
	Object *o1 = new IntegerItem(5);
	Object *o2 = new DoubleItem(7.0);
	Object *o3 = new StringItem("String123");
	l.push_back(*o1);
	l.push_back(*o2);
	l.push_back(*o3);
	l.length();
	return 0;
}
