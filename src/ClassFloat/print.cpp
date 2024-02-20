#include "ClassFloat.h"
#include <iostream>
#include <string>

void Float::print() {
    format();
    if (isNegative) {
        std::cout << "-";
    }
    if (exponent < mantissa.size()) {
        for (int i = 0; i < exponent; i++) {
            std::cout << mantissa[i];
            if ((exponent - i - 1) % 3 == 0 && (exponent - i - 1)) {
                std::cout << ',';
            }
        }
        std::cout << '.';
        for (int i = exponent; i < mantissa.size(); i++) {
            std::cout << mantissa[i];
        }
    } else {
        for (int i = 0; i < mantissa.size(); i++) {
            std::cout << mantissa[i];
            if ((mantissa.size() - i - 1) % 3 == 0 && (mantissa.size() - i - 1)) {
                std::cout << ',';
            }
        }
    }
    std::cout << std::endl;
}

std::string Float::toString() const {
    std::string out = "";
    if (!exponent) return "ERROR";
    if (isNegative) out += '-';
    for (int i = 0; i < exponent; i++) {
        out += mantissa[i] + '0';
        if ((exponent - i - 1) % 3 == 0 && (exponent - i - 1)) {
            out += ',';
        }
    }
    if (exponent < mantissa.size()) {
        out += '.';
        for (int i = exponent; i < mantissa.size(); i++) {
            out += mantissa[i] + '0';
        }
    }
    return out;
}