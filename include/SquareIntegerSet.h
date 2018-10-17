#ifndef SQUAREINTEGERSET_H
#define SQUAREINTEGERSET_H

#include "List.h"
#include <tgmath.h>

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const {
    squaredKey = key * key;
   
    extractedBits = squaredKey >> LowBitsToRemove;
    extractedBits = extractedBits & (0xFFFFFFFF >> (32-(int)log2(size))); 

    return extractedBits % size;	   
   }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  const int empty_since_start = -2;
  const int empty_after_removal = -1;
public:
   IntegerSetHT(int htsize);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
};

// Hash Table with Chaining
class IntegerSetHTChain : public IntegerSet {
protected:
  List *table;
public:
   IntegerSetHTChain(int htsize);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
};
#endif //SQUAREINTEGERSET_H
