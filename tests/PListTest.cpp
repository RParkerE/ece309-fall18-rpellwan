#include <stdio.h>
#include "PList.h"
#include "Object.h"
#include "String.h"
#include "Double.h"
#include "Integer.h"

int main() {
	List l = List();
	Object *o1 = new Integer(5);
	Object *o2 = new Double(7.0);
	Object *o3 = new String("String123");
	l.push_back(*o1);
	l.push_back(*o2);
	l.push_back(*o3);
	l.length();
	return 0;
}
