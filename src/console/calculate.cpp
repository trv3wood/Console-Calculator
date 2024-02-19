#include "ClassFloat.h"
#include <string>

std::string calculate(const Float& num1, const Float& num2, std::string operation) {
    Float res;
    if (operation == "+") {
        res = num1 + num2;
    } else if (operation == "-") {
        res = num1 - num2;
    } else if (operation == "*") {
        res = num1 * num2;
    } else if (operation == "/") {
        res = num1 / num2;
    }
    return res.toString();
}