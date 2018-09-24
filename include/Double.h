#ifndef DOUBLE_H
#define DOUBLE_H

#include "Object.h"

class Double : public Object {
public:
	double i;
	Double(double n = 0.0) : i(n) {}
};

#endif //DOUBLE_H