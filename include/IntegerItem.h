#ifndef INTEGERITEM_H
#define INTEGERITEM_H

#include "Object.h"

namespace ece309 {

class IntegerItem : public Object {
public:
	int i;
	IntegerItem(int n = 0) : i(n) {}
};

}

#endif //INTEGERITEM_H
