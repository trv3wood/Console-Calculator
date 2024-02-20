#include "ClassFloat.h"
#include <algorithm>
bool Float::absoluteValLessThan(const Float& other) const { 
    if (exponent != other.exponent) return exponent < other.exponent;
    for (int i = 0; i < std::min(mantissa.size(), other.mantissa.size()); i++) {
        if (mantissa[i] == other.mantissa[i]) continue;
        if (mantissa[i] < other.mantissa[i]) return true;
        else return false;
    }
    if (mantissa.size() >= other.mantissa.size()) return false;
    else return true;
}

bool Float::operator<(const Float& other) const {
    if (isNegative == other.isNegative) {
        if (!isNegative) return absoluteValLessThan(other);
        else return other.absoluteValLessThan(*this);
    } else {
        return isNegative;
    }
}

bool Float::operator==(const Float& other) const {
    return exponent == other.exponent && mantissa == other.mantissa && isNegative == other.isNegative;
}
