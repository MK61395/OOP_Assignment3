#pragma once
#include <iostream>
using namespace std;

class Flower {
	string name;
	string color;
    double pricPerUnit;
	bool perfumed;
	bool onSale;
	public:
		//setters & getters
		void setname(string n)
		{
			name = n;
		}
		string getname()
		{
			return name;
		}

		void setcolor(string c)
		{
			color = c;
		}
		string getcolor()
		{
			return color;
		}

		void setpricePerUnit(double pPU)
		{
			pricPerUnit = pPU;
		}
		double getpricePerUnit()
		{
			return pricPerUnit;
		}

		void setperfumed(bool perf)
		{
			perfumed = perf;
		}
		bool getperfumed()
		{
			return perfumed;
		}

		void setonSale(bool onS)
		{
			onSale = onS;
		}
		bool getonSale()
		{
			return onSale;
		}



		//Other functions
		Flower()  //default constructor
		{
			name = "";
			color = "";
			pricPerUnit = 0.0;
			perfumed = false;
			onSale = false;
		}

		Flower(string n, string c, double ppu)  //3 args
		{
			name = n;
			color = c;
			pricPerUnit = ppu;
		}

		Flower(string n, string c, double ppu, bool perf) //4 args
		{
			name = n;
			color = c;
			pricPerUnit = ppu;
			perfumed = perf;
		}
		
		Flower(string n, string c, double ppu, bool perf, bool onS)
		{
			name = n;
			color = c;
			pricPerUnit = ppu;
			perfumed = perf;
			onSale = onS;
		}

		//Flower(string n, string c, double ppu, bool perf = false , bool onS = false)
		//{
			/*name = n;
			color = c;
			pricPerUnit = ppu;
			perfumed = perf;
			onSale = onS;*/
		//}

		double price()
		{
			if (getonSale() == 1)
			{
				return (getpricePerUnit() / 2);
			}
			else
				return pricPerUnit;
		}

		bool perfume()
		{
			return getperfumed();
		}

		operator string() const
		{
			string s1;
			cout << "<" << name << ">" << "<" << color << ">" << "<" << perfumed << ">" << "," << " Price: " << "<" << pricPerUnit << ">" << " Rs.";
			return s1;
		}

		friend ostream& operator<<(ostream& output, const Flower& f) {
			output << "<" << f.name << ">" << "<" << f.color << ">" << "<" << f.perfumed << ">" << "," << " Price: " << "<" << f.pricPerUnit << ">" << " Rs.";
			return output;
		}

		bool operator==(Flower& f)
		{
			if (name == f.getname())
			{
				if (color == f.getcolor())
				{
					if (perfumed == f.getperfumed())
					{
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
};

class Bouquet {
	Flower* f;
public:
	Bouquet(Flower* f = NULL)
	{
		this->f = f;
	}

	bool perfume()
	{
		if (f->getperfumed() == 1)
		{
			return 1;
		}
		else
			return 0;
	}

	//double price()
	//{
		//if()
		//return f->getpricePerUnit();

	//}

	operator string() const
	{
		string res = "Still no flower in the bouquet";
		return res;
	}
//	//other operators
//	Bouquet operator +=(const Bouquet& bou)
//	{
//	}
//
//	Bouquet operator -=(const Bouquet& bou)
//	{
//	}
//
//	Bouquet operator +(const Bouquet& bou)
//	{
//	}
//
//	Bouquet operator -(const Bouquet& bou)
//	{
//	}
//
//	friend ostream& operator<<(ostream& output, const Bouquet&);
};
//
//ostream& operator<<(ostream& output, const Bouquet&)
//{
//
//}