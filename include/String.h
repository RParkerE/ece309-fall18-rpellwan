#ifndef STRING_H
#define STRING_H

#include "Object.h"

class String : public Object {
public:
  const char * str;
  String(const char *as = "")
  {
    str = as;
  }
};

#endif //STRING_H