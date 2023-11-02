#include "inf_int.h"


#define MAX_STRINGS 1001
#define ASCII_DIGIT 48

bool operator==(const inf_int& a , const inf_int& b)
{
    // we assume 0 is always positive.
    if ( (strcmp(a.digits , b.digits)==0) && a.thesign==b.thesign )
        return true;
    return false;
}
bool operator!=(const inf_int& a, const inf_int& b) {
    if ((strcmp(a.digits, b.digits) == 0) && a.thesign == b.thesign)
        return false;
    return true;
}
bool operator>(const inf_int& a, const inf_int& b) {
    if (a.thesign == true && b.thesign == false) {
        return true;
    }
    else if (a.thesign == false && b.thesign == true) {
        return false;
    }
    else if (a.thesign == true && b.thesign == true) {
        if (a.length > b.length) {
            return true;
        }
        else if (a.length < b.length) {
            return false;
        }
        else {
            for (int i = a.length - 1; i >= 0; i--) {
                if (a.digits[i] > b.digits[i]) {
                    return true;
                }
                else if (a.digits[i] < b.digits[i]) {
                    return false;
                }
                else {

                }
            }
        }
        return false;
    }
    else {
        if (a.length > b.length) {
            return false;
        }
        else if (a.length < b.length) {
            return true;
        }
        else {
            for (int i = a.length - 1; i >= 0; i--) {
                if (a.digits[i] > b.digits[i]) {
                    return false;
                }
                else if (a.digits[i] < b.digits[i]) {
                    return true;
                }
                else {

                }
            }
        }
        return true;
    }
}
bool operator<(const inf_int& a, const inf_int& b) {
    return operator>(b, a);
}
inf_int operator+(const inf_int& a, const inf_int& b){
    inf_int result;
    inf_int temp_int;
    temp_int.digits = new char[MAX_STRINGS];
    temp_int.length = MAX_STRINGS;
    temp_int.thesign = true;
    for (int i = 0; i < MAX_STRINGS; i++) {
        temp_int.digits[i] = 0;
    }
    int temp = 0;
    if (a.thesign == b.thesign) {
        temp_int.thesign = a.thesign;
        if (a.length < b.length) {
            for (int i = 0; i < b.length; i++) {
                if (i < a.length) {
                    temp_int.digits[i] = a.digits[i]%48 + b.digits[i] % ASCII_DIGIT;
                }
                else {
                    temp_int.digits[i] = b.digits[i] % ASCII_DIGIT;
                }
            } 
        }
        else {
            for (int i = 0; i < a.length; i++) {
                if (i < b.length) {
                    temp_int.digits[i] = a.digits[i] % ASCII_DIGIT + b.digits[i] % ASCII_DIGIT;
                }
                else {
                    temp_int.digits[i] = a.digits[i] % ASCII_DIGIT;
                }
            }
        }
    }
    else {
        if (a.length < b.length) {
            temp_int.thesign = b.thesign;
            for (int i = 0; i < b.length; i++) {
                if (i < a.length) {
                    temp_int.digits[i] = b.digits[i] - a.digits[i];
                }
                else {
                    temp_int.digits[i] = b.digits[i] % ASCII_DIGIT;
                }
            }
        }
        else if (a.length > b.length) {
            temp_int.thesign = a.thesign;
            for (int i = 0; i < a.length; i++) {
                if (i < b.length) {
                    temp_int.digits[i] = a.digits[i] - b.digits[i];
                }
                else {
                    temp_int.digits[i] = a.digits[i] % ASCII_DIGIT;
                }
            }
        }
        else {
            for (int i = a.length; i > 0; i--) {
                if (a.digits[i - 1] > b.digits[i - 1]) {
                    temp_int.thesign = a.thesign;
                    temp = 1;
                    break;
                }
                else if (a.digits[i - 1] < b.digits[i - 1]) {
                    temp_int.thesign = b.thesign;
                    temp = 2;
                    break;
                }
                else {
                    temp = 0;
                    continue;
                }
            }
            if (temp == 1) {
                for (int i = 0; i < a.length; i++) {
                    temp_int.digits[i] = a.digits[i] % ASCII_DIGIT - b.digits[i] % ASCII_DIGIT;
                }
            }
            else if (temp == 2) {
                for (int i = 0; i < a.length; i++) {
                    temp_int.digits[i] = b.digits[i] % ASCII_DIGIT - a.digits[i] % ASCII_DIGIT;
                }
            }
            else {
                result.length = 1;
                result.thesign = true;
                result.digits = new char[1];
                result.digits[0] = ASCII_DIGIT;
                return result;
            }
        }   
    }
    result.thesign = temp_int.thesign;
    int temp_length = 0;
    for (unsigned int i = 0; i < MAX_STRINGS; i++) {
        if (temp_int.digits[i] < 0) {
            temp_int.digits[i + 1] = temp_int.digits[i + 1] - 1;
            temp_int.digits[i] = temp_int.digits[i] + 10;
        }
        else if(temp_int.digits[i]>9) {
            temp_int.digits[i + 1] = temp_int.digits[i + 1] + temp_int.digits[i] / 10;
            temp_int.digits[i] = temp_int.digits[i] % 10;
        }
        else {
            temp_int.digits[i] = temp_int.digits[i];
        }
    }
    for (int i = MAX_STRINGS; i > 0; i--) {
        if (temp_int.digits[i-1] != 0) {
            result.length = i;
            break;
        }
    }
    result.digits = new char[result.length];
    for (int i = 0; i < result.length;i++) {
        result.digits[i] = temp_int.digits[i] + ASCII_DIGIT;
    }
    return result;
}
inf_int operator-(const inf_int& a, const inf_int& b){
    inf_int temp_a = a, temp_b = b;
    inf_int result;
    if (b.thesign == true) {
        temp_b.thesign = false;
    }
    else {
        temp_b.thesign = true;
    }
    result = operator+(temp_a, temp_b);
    return result;
}
inf_int operator*(const inf_int& a, const inf_int& b){
    inf_int result;
    inf_int temp;
    if (a.thesign != b.thesign){
        temp.thesign = false;
    }
    else {
        temp.thesign = true;
    }
    temp.length = MAX_STRINGS;
    temp.digits = new char[MAX_STRINGS];
    for (unsigned int i = 0; i < MAX_STRINGS; i++) {
        temp.digits[i] = 0;
    }
    for (unsigned int i = 0; i < a.length; i++) {
        for (int j = 0; j < b.length; j++) {
            temp.digits[i + j] = a.digits[i]% ASCII_DIGIT * b.digits[j]%48;
        }
    }
    int round_u = 0;
    for (unsigned int i = 0; i < MAX_STRINGS-1; i++) {
        temp.digits[i + 1] = temp.digits[i + 1] + temp.digits[i] / 10;
        temp.digits[i] = temp.digits[i] % 10;
    }
    result.thesign = temp.thesign;
    for (int i = MAX_STRINGS - 1; i >= 0; i--) {
        if (temp.digits[i] != NULL) {
            result.length = i + 1;
            break;
        }
    }
    result.digits = new char[result.length];
    for (unsigned int i = 0; i < result.length; i++) {
        result.digits[i] = temp.digits[i] + ASCII_DIGIT;
    }
    return result;
}
// friend inf_int operator/(const inf_int& , const inf_int&); // not required

ostream& operator<<(ostream& out, const inf_int& out_int) { 
    if (out_int.thesign){}
    else out << "-";
    for (int i = 0; i < out_int.length; i++)out << out_int.digits[out_int.length - 1 - i];
    return out;
}
