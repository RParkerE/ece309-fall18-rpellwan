#include <iostream>
#include <stdio.h>
#include InfInt.h

int main() {
  IntInf x = IntInf();
  IntInf y = IntInf(false, true, false, false, -1);
  IntInf z = IntInf();
  x = 5; x = x + 10; x = x * 2; x = x - 0;
  x = x / 3; x > 11; x < 11; x == 10;
  z = y; z = z / x; z = z * x; z = z + x;
  z = z - x;
}