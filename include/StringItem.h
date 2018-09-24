#ifndef STRINGITEM_H
#define STRINGITEM_H

#include "Object.h"

class StringItem : public Object {
public:
  const char * str;
  StringItem(const char *as = "")
  {
    str = as;
  }
};

#endif //STRINGITEM_H
