#ifndef DOUBLEITEM_H
#define DOUBLEITEM_H

#include "Object.h"

namespace ece309 {

class DoubleItem : public Object {
public:
	double i;
	DoubleItem(double n = 0.0) : i(n) {}
};

}

#endif //DOUBLEITEM_H
