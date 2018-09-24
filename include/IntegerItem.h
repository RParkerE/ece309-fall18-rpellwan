#ifndef INTEGERITEM_H
#define INTEGERITEM_H

#include "Object.h"

class IntegerItem : public Object {
public:
	int i;
	Integer(int n = 0) : i(n) {}
};

#endif //INTEGERITEM_H
