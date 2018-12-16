#include <iostream>
#include <stdio.h>
#include "InfInt.h"

using namespace ece309;

int main() {
  bool test = false;
  if(test == false){
  IntInf x = IntInf();
  IntInf y = IntInf(false, true, false, false, -1);
  IntInf z = IntInf();
  x = 5; x = x + 10; x = x * 2; x = x - 0;
  x = x / 3; 
  test = x > 11; test = x < 11;  test = x == 10;
  z = y; z = z / x; z = z * x; z = z + x;
  z = z - x;
  test = z < x;
  }
}
