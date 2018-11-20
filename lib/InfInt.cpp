#include <iostream>
#include <stdio.h>
#include "InfInt.h"

IntInf::IntInf() {
  negInf = false;
  posInf = false;
  integer = false;
  undefined = true;
  val = -1;
}

IntInf& IntInf::operator=(const IntInf &rhs) {
	if(&rhs == this) return *this;
	if(rhs.integer) 
	{
		this->val = rhs.val;
		this->undefined = false;
		this->negInf = false;
		this->posInf = false;
		this->integer = true;
	}
	else if(rhs.negInf)
	{
		this->undefined = false;
		this->integer = false;
		this->posInf = false;
		this->negInf = true;
	}
	else if(rhs.posInf)
	{
		this->undefined = false;
		this->integer = false;
		this->negInf = false;
		this->posInf = true;
	}
	return *this;
}

IntInf& IntInf::operator=(int num) {
	this->val = num;
	this->undefined=false;
	this->negInf = false;
	this->posInf = false;
	this->integer = true;
	
	return *this;
}

IntInf IntInf::operator+(const IntInf &rhs) const {
	IntInf result;
	
	if((rhs.posInf && !this->negInf) || (!rhs.negInf && this->posInf))
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	if((rhs.negInf && !this->posInf) || (!rhs.posInf && this->negInf))
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	if((rhs.posInf && this->negInf) || (rhs.negInf && this->posInf))
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	if(rhs.integer && this->integer)
	{
		result.val = this->val + rhs.val;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	return result;
}

IntInf IntInf::operator+(int num) const {
	IntInf result;
	
	if(this->posInf)
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	if(this->negInf)
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	if(this->integer)
	{
		result.val = this->val + num;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	return result;
}

IntInf IntInf::operator-(const IntInf &rhs) const {
	IntInf result;
	
	if((rhs.posInf && !this->posInf) || (!rhs.posInf && this->posInf))
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	if((rhs.negInf && !this->negInf) || (!rhs.negInf && this->negInf))
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	if((rhs.negInf && this->negInf) || (rhs.posInf && this->posInf))
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	if(rhs.integer && this->integer)
	{
		result.val = this->val - rhs.val;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	return result;
}

IntInf IntInf::operator-(int num) const {
	IntInf result;
	
	if(this->posInf)
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	if(this->negInf)
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	if(this->integer)
	{
		result.val = this->val - num;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	return result;
}

IntInf IntInf::operator*(const IntInf &rhs) const {
	IntInf result;
	
	if(this->val == 0 || rhs.val == 0)
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	else if((this->posInf && rhs.posInf) || (this->posInf && rhs.posInf) || (this->negInf && rhs.negInf) || (this->posInf && rhs.val > 0) || (this->negInf && rhs.val < 0)
		|| (this->val > 0 && rhs.posInf) || (this->val < 0 && rhs.negInf))
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	else if((this->posInf && rhs.negInf) || (this->negInf && rhs.posInf) || (this->posInf && rhs.val < 0) || (this->negInf && rhs.val > 0) || (this->val < 0 && rhs.posInf) 
		|| (this->val > 0 && rhs.negInf))
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	else if(this->integer && rhs.integer)
	{
		result.val = this->val * rhs.val;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	return result;
}

IntInf IntInf::operator*(int num) const {
	IntInf result;
	
	if(num == 0)
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}	
	else if((this->posInf && num > 0) || (this->negInf && num < 0))
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	else if((this->negInf && num > 0) || (this->posInf && num < 0))
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	else if(this->integer)
	{
		result.val = this->val * num;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	return result;
}

IntInf IntInf::operator/(const IntInf &rhs) const {
	IntInf result;
	if(rhs.integer && rhs.val == 0)
	{
		result.negInf = false;
		result.posInf = false;
		result.integer = false;
		result.undefined = true;
	}
	else if(rhs.posInf)
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	else if(rhs.negInf)
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	else if(this->integer && this->val == 0)
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	else if(this->posInf && rhs.integer)
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	else if(this->negInf && rhs.integer)
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	return result;
}

IntInf IntInf::operator/(int num) const {
	IntInf result;
	if(num == 0)
	{
		result.negInf = false;
		result.posInf = false;
		result.integer = false;
		result.undefined = true;
	}
	else if(this->integer && this->val == 0)
	{
		result.val = 0;
		result.undefined = false;
		result.negInf = false;
		result.posInf = false;
		result.integer = true;
	}
	else if(this->posInf)
	{
		result.undefined = false;
		result.integer = false;
		result.negInf = false;
		result.posInf = true;
	}
	else if(this->negInf)
	{
		result.undefined = false;
		result.integer = false;
		result.posInf = false;
		result.negInf = true;
	}
	return result;
}

bool IntInf::operator==(const IntInf &rhs) const {
	if(this->integer && rhs.integer)
	{
		if(this->val == rhs.val) return true;
		else return false;
	}
	return false;
}

bool IntInf::operator==(int num) const {
	if(this->integer) 
	{
		if(this->val == num) return true;
	}
	return false;
}

bool IntInf::operator>(const IntInf &rhs) const {
	if(this->posInf && !rhs.posInf) return true;
	else if (this->integer && rhs.integer)
	{
		if(this->val > rhs.val) return true;
	}
	return false;
}

bool IntInf::operator>(int num) const {
	if(this->posInf) return true;
	else if(this->integer)
	{
		if(this->val > num) return true;
	}
	return false;
}

bool IntInf::operator<(const IntInf &rhs) const {
	if(this->negInf && !rhs.negInf) return true;
	else if (this->integer && rhs.integer)
	{
		if(this->val < rhs.val) return true;
	}
	return false;
}

bool IntInf::operator<(int num) const {
	if(this->negInf) return true;
	else if(this->integer)
	{
		if(this->val < num) return true;
	}
	return false;
}
