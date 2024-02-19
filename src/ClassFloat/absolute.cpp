#include "ClassFloat.h"
#include <algorithm>
using std::max;
#define FL_DEBUG_ABSCPP 0

#if FL_DEBUG_ABSCPP == 1
#include <iostream>
#define LOG(x) std::cout << #x << " = " << x << std::endl;
#define LOG_VECTOR(x) std::cout << #x << " = ";\
for (int i = 0; i < x.size(); i++) {\
    std::cout << x[i] << " ";\
}\
std::cout << std::endl;
#else
#define LOG(x)
#define LOG_VECTOR(x)
#endif

Float Float::addAbsolute(const Float& a, const Float& b) const {
    Float res;
    if (a.exponent == b.exponent) {
        res.exponent = max(a.exponent, b.exponent); // 取大的指数(整数的指数为0
        int maxMantissaSize = max(a.mantissa.size(), b.mantissa.size());
        res.mantissa.resize(maxMantissaSize, 0);
        for (int i = 0; i < maxMantissaSize; i++) { // 逐位相加
            res.mantissa[i] = (i < a.mantissa.size()) ? a.mantissa[i] : 0;
            res.mantissa[i] += (i < b.mantissa.size()) ? b.mantissa[i] : 0;
        }
        int carry = 0;
        for (int i = maxMantissaSize - 1; i >= 0; i--) { // 进位
            res.mantissa[i] += carry;
            carry = res.mantissa[i] / 10;
            res.mantissa[i] %= 10;
        }
        if (carry) {
            res.mantissa.insert(res.mantissa.begin(), carry);
            res.exponent++;
        }
        LOG(res.exponent)
    } else {
        Float copy1 = a;
        Float copy2 = b;
        alignMantissa(copy1, copy2);
        return addAbsolute(copy1, copy2);
    }
    return res;
}

Float Float::subtractAbsolute(const Float& a, const Float& b) const { // |a| should > |b|
    Float res;
    if (a.exponent == b.exponent) {
        res.exponent = a.exponent;
        int maxMantissaSize = max(a.mantissa.size(), b.mantissa.size());
        res.mantissa.resize(maxMantissaSize, 0);
        LOG(res.exponent)
        
        for (int i = 0; i < maxMantissaSize; i++) { // 逐位相减
            res.mantissa[i] = (i < a.mantissa.size()) ? a.mantissa[i] : 0;
            res.mantissa[i] -= (i < b.mantissa.size()) ? b.mantissa[i] : 0;
        }
        int carry = 0;
        for (int i = maxMantissaSize - 1; i >= 0; i--) { // 借位
            res.mantissa[i] -= carry;
            if (res.mantissa[i] < 0) {
                carry = 1;
                res.mantissa[i] += 10;
            } else {
                carry = 0;
            }
        }
        LOG(res.exponent)
        LOG_VECTOR(res.mantissa)
        // 去掉前导0
        //while (res.exponent > 1 && res.mantissa[0] == 0) {
            //res.mantissa.erase(res.mantissa.begin());
            //res.exponent--;
        //}
        LOG(res.exponent)
    } else {
        Float copy1 = a;
        Float copy2 = b;
        alignMantissa(copy1, copy2);
        return subtractAbsolute(copy1, copy2);
    }
    return res;
}