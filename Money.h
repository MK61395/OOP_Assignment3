#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Cent {

public:
    int cent = 0;
    Cent() {
        cent = 0;
    }
    Cent(int val) {
        cent = val;
    }
};

class Nickel {

public:
    int nickel = 0;

    Nickel() {
        nickel = 0;
    }
    Nickel(int val) {
        nickel = val;
    }
    int getNickels() {
        return nickel;
    }
};

class Quarter {

public:
    int quarter = 0;

    Quarter() {
        quarter = 0;
    }
    Quarter(int val) {
        quarter = val;
    }
    int getQuarters() {
        return quarter;
    }

};

class Dollar {

public:
    int dollar = 0;


    Dollar() {
        dollar = 0;
    }
    Dollar(int val) {
        dollar = val;
    }

};

class Money {
    double value;
    double saved;
    Dollar d;
    Quarter q;
    Nickel n;
    Cent c;
public:
    Money() {
        value = 0;
        saved = 0;
        d.dollar = 0;
        q.quarter = 0;
        n.nickel = 0;
        c.cent = 0;
    }
    int getDollars() {
        return d.dollar;
    }
    int getQuarters() {
        return q.quarter;
    }
    int getNickels() {
        return n.nickel;
    }
    int getCents() {
        return c.cent;
    }
    void setCents(int a) {
        c.cent = a;
    }


    Money(double val) {
        saved = val;
        value = val;
        while (true) {
            if (value - 1 >= 0) {
                value--;
                d.dollar++;
                // cout << "deducting dollar\n";
                // cout << "new val : " << value << endl;
                // cout << "new dollar : " << d.dollar << endl;
            }
            else {
                // cout << "breaked " << endl;
                break;
            }


        }
        while (true) {
            if (value - 0.25 >= 0) {
                value -= 0.25;
                q.quarter++;
            }
            else {
                break;
            }
            // cout << "deducting quarter\n";
            // cout << "new val : " << value << endl;
        }
        while (true) {
            if (value - 0.05 >= 0) {
                value -= 0.05;
                n.nickel++;
            }
            else {
                break;
            }

            //  cout << "deducting nickel\n";
             // cout << "new val : " << value << endl;
        }
        while (value > 0) {
            if ((value - 0.01) > -0.001) {
                value -= 0.01;
                c.cent++;
            }
            else {
                break;
            }
            /* cout << "deducting cent\n";
             cout << "new val : " << value << endl;*/
        }
    }

    //Implement getters and setter functions

    Money operator+(Money m) {
        this->saved += m.saved;
        this->value = saved;
        Money temp(saved);
        return temp;
    }


    Money operator-(Money m) {
        this->saved -= m.saved;
        this->value = saved;
        Money temp(saved);
        return temp;
    }

    Money operator+(Dollar d) {
        this->saved += d.dollar;
        this->value = saved;
        Money temp(saved);
        return temp;
    }
    Money operator-(Dollar d) {
        this->saved -= d.dollar;
        this->value = saved;
        Money temp(saved);
        return temp;
    }


    Money operator+(Nickel d) {
        /* cout << "current val = " << this->saved << endl;
         cout << "now adding " << (0.05 * d.nickel) << endl;*/
        this->saved += (0.05 * d.nickel);
        //cout << "new val : " << this->saved << endl;
        this->value = saved;
        Money temp(saved);
        return temp;
    }
    Money operator-(Nickel d) {
        /* cout << "current val = " << this->saved << endl;
         cout << "now deducting " << (0.05 * d.nickel) << endl;*/
        this->saved -= (0.05 * d.nickel);
        this->value = this->saved;
        Money temp(this->saved);
        return temp;
    }

    Money operator+(Quarter d) {
        this->saved += (0.25 * d.quarter);
        this->value = this->saved;
        Money temp(this->saved);
        return temp;
    }
    Money operator-(Quarter d) {
        this->saved -= (0.25 * d.quarter);
        this->value = this->saved;
        Money temp(this->saved);
        return temp;
    }


    Money operator+(Cent d) {
        this->saved += (0.01 * d.cent);
        this->value = this->saved;
        Money temp(this->saved);
        return temp;
    }
    Money operator-(Cent d) {
        this->saved -= (0.01 * d.cent);
        this->value = this->saved;
        Money temp(this->saved);
        return temp;
    }

    //These are all addition and subtraction on overloads to add specific coins to the total amount of money


    Money operator ++ (int) {
        /*  cout << "no of dollars are " << d.dollar << endl;
          cout << "value is " << saved << endl;*/
        float temp = (float)saved - (float)d.dollar;
        //cout << "value without dollars is : " << temp << endl;

        while (fmod(temp, 0.25) != 0) {
            temp += 0.01;
        }

        // cout << "rounded value is " << (double)d.dollar + temp << endl;
        Money temporary((double)d.dollar + temp);
        // cout << "checking dollar rate : " << temporary.getDollars() << endl;
        *this = temporary;
        return *this;
    }


    Money operator -- (int) {
        /* cout << "no of dollars are " << d.dollar << endl;
         cout << "value is " << saved << endl;*/
        float temp = (float)saved - (float)d.dollar;
        // cout << "value without dollars is : " << temp << endl;

        float check = (float)saved - fmod(temp, 0.25);

        //cout << "rounded value is " << check << endl;
        Money temporary(check);
        // cout << "checking dollar rate : " << temporary.getDollars() << endl;
        *this = temporary;
        return *this;
    }

    bool operator >= (Money m) {
        if (this->saved >= m.saved) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator <= (Money m) {
        if (this->saved <= m.saved) {
            return true;
        }
        else {
            return false;
        }
    }
    //Comparison operators

    Quarter operator !() {
        double temp = saved;
        Quarter q2;
        while (1) {
            // cout << temp << endl;
            temp -= 0.25;
            if (temp >= 0) {
                q2.quarter++;
            }
            else {
                break;
            }


        }
        return q2;
    }

    //Returns the maximum number of quarters that can be obtained from Money

    Nickel operator ~ () {
        double temp = saved;
        Nickel n2;
        while (1) {
            //cout << temp << endl;
            temp -= 0.05;
            if (temp >= 0) {
                n2.nickel++;
            }
            else {
                break;
            }
        }
        return n2;
    }

    //Returns the maximum number of nickels that can be obtained from Money

    Money operator/(int n) {
        double temp = saved;
        temp /= n;
        Money m(temp);
        return m;
    }

    //Returns the money object created if the current money amount were divided into n
    //parts

    Money operator*(int n) {
        double temp = saved;
        temp *= n;
        Money m(temp);
        return m;
    }
    //Returns the money object created by multiplying the current total amount by n

    //friend 
};