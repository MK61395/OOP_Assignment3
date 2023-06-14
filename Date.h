#pragma once
#include <iostream>
using namespace std;


class Date {
	int *Day;
	int *Month;
	int *Year;
public:
	// provide definitions of following functions...
	Date()
	{
		Day = new int;
		*Day = 0;
		Month = new int;
		*Month = 0;
		Year = new int;
		*Year = 0;
	}
	Date(int year, int month, int day)
	{
		Day = new int;
		*Day = day;
		Month = new int;
		*Month = month;
		Year = new int;
		*Year = year;
	}
	Date(Date& d)
	{
		Day = new int;
		*Day = *d.Day;
		Month = new int;
		*Month = *d.Month;
		Year = new int;
		*Year = *d.Year;
	}
	//implement mutators for all private data members
	//implement accessors for all private data members

	void setDay(int D)
	{
		*Day = D;
	}
	int getDay()
	{
		return *Day;
	}

	void setMonth(int M)
	{
		if (M >= 1 && M <= 12)
			*Month = M;
		else
			*Month = 1;
	}
	int getMonth()
	{
		return *Month;
	}

	void setYear(int Y)
	{
		*Year = Y;
	}
	int getYear()
	{
		return *Year;
	}

	bool isLeapYear()
	{
		if (getYear() % 4 == 0)
		{
			if (getYear() % 100 == 0)
			{
				if (getYear() % 400 == 0)
				{
					return true;
				}
				else
					return false;
			}
			else
				return true;
		}
		else
			return false;
	}

	string ToString()
	{
		//cout << getYear() << "/" << getMonth() << "/" << getDay() << endl;
		string y1;
		y1 = ToString();
		string m1;
		m1 = ToString();
		string d1;
		d1 = ToString();
		string date = y1 + "/0" + m1 + "/" + d1;
		return date;
	}

	//operatorsssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

	//void operator=(Date &d)
//	{
	//	this->setDay(*d.Day); //= *d.Day;
	//	this->setMonth(*d.Month);
	//	this->setYear(*d.Year);
	//}
	

	Date operator=(Date d)
	{
		//this->Day = d.getDay();
		this->Day = d.Day;
		this->Month = d.Month; 
		this->Year = d.Year;
		return *this;
	}

	Date operator+(int a)
	{
		this->Day = this->Day + a;
		if (*this->Day >= 31)
		{
			this->Month = this->Month + 1;
			*this->Day = 1;
			this->Day = this->Day + *Day;
		}
		else if (*Month == 12)
		{
			this->Year = this->Year + 1;
			*this->Month = 1;
			this->Month = this->Month + *Month;
			*this->Day = 1;
			this->Day = this->Day + *Day;
		}

		return *this;
	}

	Date operator-(int a)
	{
		this->Day = this->Day - a;
		
		return *this;
	}

	Date operator+(Date d)
	{
		//Date dt;
		//dt.Day = this->Day + *d.Day;
		//dt.Month = this->Month + *d.Month;
		//dt.Year = this->Year + *d.Year;
		//return dt;
		this->Day = this->Day + *d.Day;
		this->Month = this->Month + *d.Month;
		//this->Year = this->Year + *d.Year;
		if (*this->Day == 32)
		{
			this->Month = this->Month + 1;
			*this->Day = 1;
			this->Day = this->Day + *Day;
		}
		else if (*Month == 12)
		{
			this->Year = this->Year + 1;
			*this->Month = 1;
			this->Month = this->Month + *Month;
			*this->Day = 1;
			this->Day = this->Day + *Day;
		}

		return *this;
	}

	int operator-(Date d)
	{
		Date dt;
		dt.Day = this->Day - *d.Day;
		dt.Month = this->Month - *d.Month;
		dt.Year = this->Year - *d.Year;
		//return dt;
		return 1;
	}

	bool operator>(Date d)
	{
		if (this->Year > d.Year)
			return 1;
		else
			return 0;
	}

	bool operator>=(Date d)
	{
		if (this->Year >= d.Year)
			return 0;
		else 
			return 1;
	}

	bool operator<(Date d)
	{
		if (this->Year < d.Year)
			return 1;
		else
			return 0;
	}

	bool operator<=(Date d)
	{
		if (this->Year <= d.Year)
			return 1;
		else
			return 0;
	}

	bool operator!=(Date d)
	{
		if (this->Day != d.Day && this->Month != d.Month && this->Year != d.Year)
			return 1;
		else
			return 0;
	}

	bool operator==(Date d)
	{
		if (this->Day == d.Day && this->Month == d.Month && this->Year == d.Year)
			return 0;
		else
			return 1;
	}
};
