#include "IntArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace ece309 {

IntArray IntArray::operator+(const IntArray &rhs) const {
  IntArray result(length); // make object to hold return value,
                           // make long enough to hold this object’s data
  int i = 0;
  for (i = 0; i < length && i < rhs.length; i++)
    result.array[i] = array[i] + rhs.array[i];
  for (; i < length; i++) // if rhs.length is shorter, copy rest of array
    result.array[i] = array[i];
  return result;
}

int &IntArray::operator[](int index) { return array[index]; }

IntArray &IntArray::operator+=(const IntArray &rhs) {
  int l = rhs.length;
  if (l > length)
    l = length;
  for (int i = 0; i < l; i++)
    array[i] += rhs.array[i];
  return *this; // reference to this object
}

IntArray IntArray::operator-(const IntArray &rhs) const {
  IntArray result(length); // make object to hold return value,
                           // make long enough to hold this object’s data
  int i = 0;
  for (i = 0; i < length && i < rhs.length; i++)
    result.array[i] = array[i] - rhs.array[i];
  for (; i < length; i++) // if rhs.length is shorter, copy rest of array
    result.array[i] = array[i];
  return result;
}

IntArray IntArray::operator*(int x) const {
  IntArray result(length); // make object to hold return value,
                           // make long enough to hold this object’s data
  int i = 0;
  for (i = 0; i < length; i++)
    result.array[i] = array[i] * x;

  return result;
}

IntArray IntArray::operator/(int x) const {
  IntArray result(length); // make object to hold return value,
                           // make long enough to hold this object’s data
  int i = 0;
  for (i = 0; i < length; i++)
    result.array[i] = array[i] / x;

  return result;
}

IntArray IntArray::operator<<(int count) const {
  IntArray result(length); // make object to hold return value,
                           // make long enough to hold this object’s data
  int i = 0;

  for (i = 1; i < length; i++)
    result.array[i] = array[i - 1];

  result.array[0] = array[length - 1];

  return result;
}

IntArray::operator char *() const {
  char *str = new char[length + 1];
  for (int i = 0; i < length; i++)
    if (array[i] >= 0 && array[i] < 255)
      str[i] = (char)array[i];
    else
      str[i] = ' ';
  str[length] = 0;
  return str;
}

IntArray::operator int() const {
  int average = 0;
  for (int i = 0; i < length; i++)
    average += array[i];
  return average / length;
}

}