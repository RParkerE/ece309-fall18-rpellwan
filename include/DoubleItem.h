#ifndef DOUBLEITEM_H
#define DOUBLEITEM_H

#include "Object.h"

class DoubleItem : public Object {
public:
	double i;
	Double(double n = 0.0) : i(n) {}
};

#endif //DOUBLEITEM_H
