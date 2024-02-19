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
    bool operator<=(const Float &other) const;

    Float operator+(const Float &other) const;
    Float operator-(const Float &other) const;
    Float operator*(const Float &other) const;
    Float operator/(const Float &other) const;

    Float divide(const long double& divisor, int divisorLen) const;

    void print();
    std::string toString() const;
    void format();

private:
    bool isNegative = false;   // true for negative numbers
    std::vector<int> mantissa; // 尾数
    int exponent;              // 指数

    void alignMantissa(Float &a, Float &b) const;
    bool absoluteValLessThan(const Float &other) const; // <
    Float subtractAbsolute(const Float &a, const Float &b) const;
    Float addAbsolute(const Float &a, const Float &b) const;
    bool isZero() const;
    void roundMantissa();
};