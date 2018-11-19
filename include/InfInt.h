#ifndef INFINT_H
#define INFINT_H

#include <iostream>
#include <stdio.h>

class IntInf {
	
private:
	
	bool negInf;
	bool integer;
	bool posInf;
	bool undefined;
	int val;
	
public:
	
	IntInf(bool, bool, bool, bool, int);
	IntInf& operator=(const IntInf &rhs);
	IntInf operator+(const IntInf &rhs) const;
	IntInf operator-(const IntInf &rhs) const;
	IntInf operator*(const IntInf &rhs) const;
	IntInf operator/(const IntInf &rhs) const;
	bool operator==(const IntInf &rhs) const;
	bool operator<(const IntInf &rhs) const;
	bool operator>(const IntInf &rhs) const;
	IntInf& operator=(int);
	IntInf operator+(int) const;
	IntInf operator-(int) const;
	IntInf operator*(int) const;
	IntInf operator/(int) const;
	bool operator==(int) const;
	bool operator<(int) const;
	bool operator>(int) const;
};

#endif //INFINT_H