#include "Polynomial.h"
#include <iostream>
using namespace std;


void Polynomial::setcoeff(int c)
	{
		degree = c;
	}
int Polynomial::getcoeff()
	{
		return degree;
	}

	//include all the necessary checks before performing the operations in the functions
Polynomial::Polynomial() // a default constructor
	{
		//coefficient = 0;
		degree = 0;
		polynom = "";
	}
Polynomial::Polynomial(int c) // a parameterized constructor, received the highest degree of polynomial
	{
		//coefficient = c;
		degree = c;
		polynom = c;
	}
Polynomial::Polynomial(const Polynomial& co) // a copy constructor
{
	degree = co.degree;
	polynom = co.polynom;
}

Polynomial Polynomial::operator=(const Polynomial& rhs)
{
	this->polynom = rhs.polynom;
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& add)
{
	//Polynomial result;
	//result = this->coefficient + add.coefficient;
	//return result;
	this->polynom = this->polynom + add.polynom;
	return *this;
}

Polynomial Polynomial::operator-(const Polynomial& sub)
{
	//this->polynom = this->polynom - sub.polynom;
	return *this;
}

void Polynomial::operator+=(const Polynomial& adds) // adds two Polynomials
{
	this->polynom = this->polynom += adds.polynom;
}

void Polynomial::operator-=(const Polynomial& subs)
{
	//this->polynom = this->polynom -= subs.polynom;
}

bool Polynomial::operator==(const Polynomial& coe)
{
	if (this->polynom == coe.polynom)
	{
		return 1;
	}

	else if (this->polynom != coe.polynom)
	{
		return 0;
	}
}

Polynomial::operator string() const// returns the value of the Polynomial as a string like “4x^3 + 3x + 2”
{
	return polynom;
}

istream& operator>>(istream& input, Polynomial& coef)
{
	getline(input, coef.polynom);
	return input;
}
ostream& operator<<(ostream& output, const Polynomial& coef)
{
	output << coef.polynom;
	return output;
}

Polynomial::~Polynomial()// destructor
{
}



