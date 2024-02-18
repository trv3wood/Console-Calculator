#pragma once
#include <vector>
void roundMantissa(std::vector<int>& mantissa); 
std::vector<int> multiplyByDigit(const std::vector<int>&, int quotientDigit);
bool isLessThan(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2); 
std::vector<int> subtractMantissas(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2);
