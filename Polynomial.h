#pragma once
/*
 * Polynomial.h
 *
 *  Created on: Oct 21, 2022
 *      Author:
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include <string>
using namespace std;

class Polynomial {
	// think about the private data members (coefficient values can be of type int)
	//int coefficient;
	int degree;
	string polynom;
public:
	void setcoeff(int);
	int getcoeff();
	//include all the necessary checks before performing the operations in the functions
	Polynomial(); // a default constructor
	Polynomial(int); // a parameterized constructor, received the highest degree of polynomial
	Polynomial(const Polynomial&); // a copy constructor

	// Binary Operators
	// Assignment Operator
	Polynomial operator=(const Polynomial& rhs); //assigns (copies) the rhs Polynomial to "this" Polynomial
	// Arithmetic Operators
	Polynomial operator+(const Polynomial&); // adds two Polynomials and returns the result
	Polynomial operator-(const Polynomial&); // subtracts two Polynomials and returns the result
	// Compound Assignment Operators
	void operator+=(const Polynomial&); // adds two Polynomials
	void operator-=(const Polynomial&); // subtracts two Polynomials
	// Logical Operator
	bool operator==(const Polynomial&); // compares and returns true if equal

	friend ostream& operator<<(ostream& output, const Polynomial&); // outputs the Polynomial
	friend istream& operator>>(istream& input, Polynomial&); // inputs the Polynomial
	// Conversion Operator
	operator string() const; // returns the value of the Polynomial as a string like “4x^3 + 3x + 2”
	~Polynomial(); // destructor

};

//friend ostream& operator<<(ostream& output, const Polynomial&); // outputs the Polynomial
//friend istream& operator>>(istream& input, Polynomial&); // inputs the Polynomial


#endif /* POLYNOMIAL_H_ */

