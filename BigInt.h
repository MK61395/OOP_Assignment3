#pragma once
/*
 * BigInt.h
 *
 *  Created on: Oct 21, 2022
 *      Author:
 */

#ifndef BIGINT_H_
#define BIGINT_H_
#include<string>
using namespace std;

class BigInt
{
	//think about the private data members
	int bigint;
	string bigstring;
public:
	void setbigint(int);
	int getbigint();
	void setbigstring(string);
	string getbigstring();

	BigInt(int val = 0);
	BigInt(const string& text);
	BigInt(const BigInt& copy); // copy constructor

	// Binary Operators
	// Arithmetic Operators
	BigInt operator+(const BigInt& val) const;
	BigInt operator+(int val) const;
	BigInt operator-(const BigInt& val) const;
	BigInt operator-(int val) const;
	BigInt operator*(const BigInt& val) const;
	// Compound Assignment Operators
	BigInt operator+=(const BigInt& rhs);
	BigInt operator-=(const BigInt& rhs);
	BigInt operator*=(const BigInt& rhs);
	// Logical Operators
	bool operator==(const BigInt& val) const;
	bool operator!=(const BigInt& val) const;
	bool operator<(const BigInt& val) const;
	bool operator<=(const BigInt& val) const;
	bool operator>(const BigInt& val) const;
	bool operator>=(const BigInt& val) const;

	// Unary Operators
	BigInt& operator++();  // Pre-increment Operator
	BigInt operator++(int);  // Post-increment Operator
	BigInt& operator--();  // Pre-decrement Operator
	BigInt operator--(int); // Post-decrement Operator

	//Conversion Operator
	operator string();    // return value of the BigInt as string
	~BigInt(); // destructor

	friend ostream& operator<<(ostream& output, const BigInt& val); // outputs the BigInt
	friend istream& operator>>(istream& input, BigInt& val); // inputs the BigInt
};

//ostream& operator<<(ostream& output, const BigInt& val); // outputs the BigInt
//istream& operator>>(istream& input, BigInt& val); // inputs the BigInt


#endif /* BIGINT_H_ */
