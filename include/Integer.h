#ifndef INTEGER_H
#define INTEGER_H

#include "Object.h"

class Integer : public Object {
public:
	int i;
	Integer(int n = 0) : i(n) {}
};

#endif //INTEGER_H