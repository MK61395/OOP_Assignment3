#include <iostream>
#include "BigInt.h"
using namespace std;

void BigInt::setbigint(int b)
{
	bigint = b;
}
int BigInt::getbigint()
{
	return bigint;
}

void BigInt::setbigstring(string s)
{
	bigstring = s;
}

string BigInt::getbigstring()
{
	return bigstring;
}
//other funcs

BigInt::BigInt(int val)
{
	bigint = val;
}
BigInt::BigInt(const string& text)
{
	bigstring = text;
}
BigInt::BigInt(const BigInt& copy) // copy constructor
{
	bigint = copy.bigint;
}

// Binary Operators
// Arithmetic Operators

BigInt BigInt::operator+(const BigInt& val) const
{
	//this->bigint =
	this->bigint + val.bigint;
	this->bigstring + val.bigstring;
	return *this;
}
BigInt BigInt::operator+(int val) const
{
	return this->bigint + val;
}
BigInt BigInt::operator-(const BigInt& val) const
{
	return this->bigint - val.bigint;
}
BigInt BigInt::operator-(int val) const
{
	return this->bigint - val;
}
BigInt BigInt::operator*(const BigInt& val) const
{
	return this->bigint * val.bigint;
}

// Compound Assignment Operators
BigInt BigInt::operator+=(const BigInt& rhs)
{
	return this->bigint += rhs.bigint;
}

BigInt BigInt::operator-=(const BigInt& rhs)
{
	return this->bigint -= rhs.bigint;
}

BigInt BigInt::operator*=(const BigInt& rhs)
{
	return this->bigint *= rhs.bigint;
}
// Logical Operators
bool BigInt::operator==(const BigInt& val) const
{
	if (this->bigint == val.bigint)
	{
		return 1;
	}
	else
		return 0;
}
bool BigInt::operator!=(const BigInt& val) const
{
	if (this->bigint != val.bigint)
	{
		return 1;
	}
	else
		return 0;
}
bool BigInt::operator<(const BigInt& val) const
{
	if (this->bigint < val.bigint)
	{
		return 1;
	}
	else
		return 0;
}
bool BigInt::operator<=(const BigInt& val) const
{
	if (this->bigint <= val.bigint)
	{
		return 1;
	}
	else
		return 0;
}
bool BigInt::operator>(const BigInt& val) const
{
	if (this->bigint > val.bigint)
	{
		return 1;
	}
	else
		return 0;
}
bool BigInt::operator>=(const BigInt& val) const
{
	if (this->bigint >= val.bigint)
	{
		return 1;
	}
	else
		return 0;
}

// Unary Operators
BigInt& BigInt::operator++()  // Pre-increment Operator
{
	bigint = ++bigint;
	return *this;
}
BigInt BigInt::operator++(int)  // Post-increment Operator
{
	bigint = bigint++;
	return *this;
}
BigInt& BigInt::operator--()  // Pre-decrement Operator
{
	bigint = --bigint;
	return *this;
}
BigInt BigInt::operator--(int) // Post-decrement Operator
{
	bigint = bigint++;
	return *this;
}

//Conversion Operator
BigInt::operator string()    // return value of the BigInt as string
{
	return bigstring;
}

ostream& operator<<(ostream& output, const BigInt& val) // outputs the BigInt
{
	output << val.bigstring;
	return output;
}
istream& operator>>(istream& input, BigInt& val) // inputs the BigInt
{
	getline(input, val.bigstring);
	return input;
}

BigInt::~BigInt() // destructor
{

}