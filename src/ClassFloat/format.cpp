#include "ClassFloat.h"

void Float::format() {
    while (exponent > 1 && mantissa[0] == 0) {
        mantissa.erase(mantissa.begin());
        exponent--;
    }

    if (exponent < mantissa.size()) {
        for (int i = mantissa.size() - 1; i >= exponent; i--) {
            if (mantissa[i] == 0) {
                mantissa.erase(mantissa.begin() + i);
            } else {
                break;
            }
        }
    }

    if (isNegative && mantissa.size() == 1 && mantissa[0] == 0) {
        isNegative = false;
    }
}

void Float::alignMantissa(Float& a, Float& b) {
    if (a.exponent > b.exponent) {
        b.mantissa.insert(b.mantissa.begin(), a.exponent - b.exponent, 0);
        b.exponent = a.exponent;
    } else if (a.exponent < b.exponent) {
        a.mantissa.insert(a.mantissa.begin(), b.exponent - a.exponent, 0);
        a.exponent = b.exponent;
    }
}