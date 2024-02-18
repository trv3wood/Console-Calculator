#include "ClassFloat.h"
#include <string>
#include <stdexcept>
using std::string;
Float::Float(const std::string& number) {
    *this = number;
}

Float Float::operator=(const std::string& number) {
    if (number.empty()) {
        throw std::invalid_argument("Input string is empty");
    }
    mantissa.clear();
        
    size_t numberStart = 0;
    // 处理符号位
    if (number[0] == '-') {
        isNegative = true; // 负数
        numberStart = 1;
    } else {
        isNegative = false; // 正数
    }
    // 查找小数点的位置
    size_t pointPos = number.find('.', numberStart);

    if (pointPos == string::npos) { // 指数
        exponent = number.size() - numberStart;
    } else {
        exponent = pointPos - numberStart;
    }

    if (number.find(',', numberStart) != string::npos) {
        exponent -= (exponent / 4); // 逗号的影响
    }

    for (int i = numberStart; i < number.size(); i++) { // 尾数
        if (number[i] == ',' || number[i] == '.') continue;
        else mantissa.push_back(number[i] - '0');
    }
    return *this;
}

