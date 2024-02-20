#pragma once
#include <string>
#include <vector>
class Float {
public:
    Float(const std::string &number = "0");
    Float(const Float &) = default;
    Float(Float &&) = default;
    Float &operator=(const Float &) = default;
    Float &operator=(Float &&) = default;
    Float operator=(const std::string &number);
    Float operator=(int number);

    bool operator<(const Float &other) const;
    bool operator==(const Float& other) const;

    Float operator+(Float &other);
    Float operator-(Float &other);
    Float operator*(const Float &other) const;
    Float operator/(const Float &other) const;

    void print();
    std::string toString() const;
    void format();

private:
    bool isNegative = false;   // true for negative numbers
    std::vector<int> mantissa; // 尾数
    int exponent;              // 指数

    void alignMantissa(Float &a, Float &b);
    bool absoluteValLessThan(const Float &other) const; // <
    Float subtractAbsolute(Float &a, Float &b);
    Float addAbsolute(Float &a, Float &b);
    void roundMantissa();
};