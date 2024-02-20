#include "ClassFloat.h"
#include "divide.h"
#include <vector>
#define FL_DEBUG_CALCPP 0

#if FL_DEBUG_CALCPP == 1
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

Float Float::operator+(Float& other) {
    Float res;
    if (isNegative == other.isNegative) {
        res = addAbsolute(*this, other);
        res.isNegative = isNegative;
    } else {
        if (absoluteValLessThan(other)) {
            res = subtractAbsolute(other, *this);
            res.isNegative = other.isNegative;
        } else {
            res = subtractAbsolute(*this, other);
            res.isNegative = isNegative;
        }
        res.format();
    }
    return res;
}

Float Float::operator-(Float& other) {
    Float res;
    if (*this == other) return res;
    if (isNegative != other.isNegative) {
        res = addAbsolute(*this, other);
        res.isNegative = isNegative;
    } else {
        if (absoluteValLessThan(other)) {
            res = subtractAbsolute(other, *this);
            res.isNegative = !other.isNegative;
        } else {
            res = subtractAbsolute(*this, other);
            res.isNegative = isNegative;
        }
        res.format();
    }
    return res;
}

Float Float::operator*(const Float& other) const {
    Float zero;
    if (*this == zero || other == zero) return zero;
    Float res;
    res.mantissa.clear();
    res.mantissa.resize(mantissa.size() + other.mantissa.size() - 1, 0);

    // 计算指数
    int exponent1 = exponent ? mantissa.size() - exponent : 0;
    LOG(exponent1)
    int exponent2 = other.exponent ? other.mantissa.size() - other.exponent : 0;
    LOG(exponent2)
    res.exponent = res.mantissa.size() - exponent1 - exponent2;
    
    // 计算尾数
    for (int i = 0; i < mantissa.size(); i++) {
        for (int j = 0; j < other.mantissa.size(); j++) {
            res.mantissa[i + j] += mantissa[i] * other.mantissa[j];
        }
    }
    int carry = 0;
    for (int i = res.mantissa.size() - 1; i >= 0; i--) {
        res.mantissa[i] += carry;
        carry = res.mantissa[i] / 10;
        res.mantissa[i] %= 10;
    }
    if (carry) {// 如果最高位有进位
        res.mantissa.insert(res.mantissa.begin(), carry);
        res.exponent++;// 如果有进位，指数+1
    }
    res.isNegative = isNegative != other.isNegative;
    // res.format();
    return res;
}

Float Float::operator/(const Float& divisor) const {
    // 处理除以0的情况
    if (divisor.absoluteValLessThan(Float("0.000001"))) {
        Float error;
        error.exponent = 0;
        return error;
    }
    // 初始化结果
    Float result;
    // 除数为1
    if (divisor==Float("1")) {
        result = *this;
        result.roundMantissa();
        return result;
    }
    if (divisor==Float("-1")) {
        result = *this;
        result.isNegative = !isNegative;
        result.roundMantissa();
        return result;
    }

    // 去掉除数前导0
    std::vector<int> div(divisor.mantissa);
    while (div[0] == 0) {
        div.erase(div.begin());
    }
    std::vector<int> dividend(mantissa);
    while (dividend[0] == 0) {
        dividend.erase(dividend.begin());
    }
    dividend.insert(dividend.end(), 11, 0);
    
    auto p = result.mantissa.get_allocator().allocate(dividend.size());
    std::vector<int> remainder;
    auto ptr = remainder.get_allocator().allocate(dividend.size());
    // 执行长除法
    for (int i = 0; i < dividend.size(); i++) {
        remainder.push_back(dividend[i]);
        
        while (remainder[0] == 0 && remainder.size() > 1) {
            remainder.erase(remainder.begin());
        }
        if (isLessThan(remainder, div) || remainder[0] == 0) { // 如果余数小于除数
            result.mantissa.push_back(0);
            if (i < dividend.size() - 11) result.exponent++;
            continue;
        }

        int quotientDigit = 1;
        while (true) {
            std::vector<int> tempDiv = multiplyByDigit(div, quotientDigit);
            LOG(quotientDigit)
            LOG_VECTOR(tempDiv)
            LOG_VECTOR(remainder)
            LOG(isLessThan(remainder, tempDiv))
            if (isLessThan(remainder, tempDiv)) {
                quotientDigit--;
                break;
            } else if (remainder == tempDiv) {
                break;
            }
            quotientDigit++;
        }
        result.mantissa.push_back(quotientDigit); // 保存商的一位
        LOG_VECTOR(result.mantissa)

        // 处理结果的尾数和指数
        if (i < dividend.size() - 11) result.exponent++;
        remainder = subtractMantissas(remainder, multiplyByDigit(div, quotientDigit));
    }
    // 结果的符号
    result.isNegative = (isNegative != divisor.isNegative);
    // 处理指数
    int dividendExp = mantissa.size() - exponent;
    int divisorExp = divisor.mantissa.size() - divisor.exponent;
    result.exponent = result.exponent - dividendExp + divisorExp; 

    result.format();
    // 四舍五入
    result.roundMantissa(); 
    
    return result;
}
