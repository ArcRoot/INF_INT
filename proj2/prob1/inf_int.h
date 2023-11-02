#pragma once
#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>

using namespace std;

class inf_int
{
private:
    char* digits;  // You may modify this to "string digits;" if you want.
    unsigned int length;
    bool thesign;   // true if positive , false if negative.

public:
    inf_int() {
        thesign = true;
        length = 1;
        digits = new char[1];
        digits[0] = '0';
    };
    inf_int(int n) {
        int temp = n;
        int cnt = 0;
        if (n < 0) { 
            thesign = false; 
            temp = -temp;
            n = -n;
        }
        else thesign = true;
        while (temp != 0) {
            temp = temp / 10;
            cnt++;
        }
        length = cnt;
        digits = new char[length];
        for (int i = 0; i < length; i++) {
            digits[i] = n % 10 + 48;
            n = n / 10;
        }
    };
    inf_int(const char* c) {
        if (c[0] == '-') {
            thesign = false;
            length = strlen(c) - 1;
            digits = new char[length];
            for (int i = 0; i < length; i++) {
                digits[i] = c[length - i];
            }
        }
        else { 
            thesign = true;
            length = strlen(c);
            digits = new char[length];
            for (int i = 0; i < length; i++) {
                digits[i] = c[length - i - 1];
            }
        }
        
    };
    inf_int(const inf_int& cp) {
        thesign = cp.thesign;
        length = cp.length;
        digits = new char[length];
        for (int i = 0; i < inf_int::length; i++) {
            digits[i] = cp.digits[i];
        }
    };
    ~inf_int() {
        cout << "dealloc inf_int" << endl;
        delete[] digits;
    };

    inf_int& operator=(const inf_int& cp) {
        if (this == &cp)return *this;
        this->thesign = cp.thesign;
        this->length = cp.length;
        this->digits = new char[this->length];
        for (int i = 0; i < cp.length; i++) {
            this->digits[i] = cp.digits[i];
        }
        return *this;
    }// assignment operator

    friend bool operator==(const inf_int&, const inf_int&);
    friend bool operator!=(const inf_int&, const inf_int&);
    friend bool operator>(const inf_int&, const inf_int&);
    friend bool operator<(const inf_int&, const inf_int&);

    friend inf_int operator+(const inf_int&, const inf_int&);
    friend inf_int operator-(const inf_int&, const inf_int&);
    friend inf_int operator*(const inf_int&, const inf_int&);
    // friend inf_int operator/(const inf_int& , const inf_int&); // not required

    friend ostream& operator<<(ostream&, const inf_int&);
    // friend istream& operator>>(istream& , inf_int&);    // not required
};

#endif