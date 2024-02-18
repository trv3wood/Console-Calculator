#include <vector>
#include "ClassFloat.h"
// 辅助函数，用于尾数的乘法，这里只是一个示意
std::vector<int> multiplyByDigit(const std::vector<int>& mantissa, int digit) {
    // 实现尾数和一个数字的乘法
    std::vector<int> res(mantissa);
    int start = 0;
    for (int i = 0; i < mantissa.size(); i++) {
        if (mantissa[i] > 0) {
            start = i; break;
        }
    }
    int carry = 0;
    for (int i = res.size() - 1; i >= start; i--) {
        res[i] = res[i] * digit + carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    if (carry) res.insert(res.begin() + start, carry);
    return res;
}

// 辅助函数，用于判断第一个尾数是否小于第二个尾数
bool isLessThan(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2) {
    // 实现尾数的比较
    int start1 = 0, start2 = 0;
    for (int i = 0; i < mantissa1.size(); i++) {
        if (mantissa1[i] > 0) {
            start1 = i; break;
        }
    }
    for (int i = 0; i < mantissa2.size(); i++) {
        if (mantissa2[i] > 0) {
            start2 = i; break;
        }
    }
    if (mantissa1.size() - start1 < mantissa2.size() - start2) return true;
    if (mantissa1.size() - start1 > mantissa2.size() - start2) return false;
    for (int i = start1; i < mantissa1.size(); i++) {
        if (mantissa1[i] < mantissa2[i]) return true;
        if (mantissa1[i] > mantissa2[i]) return false;
    }
    return false;
}

// 辅助函数，用于尾数的减法
std::vector<int> subtractMantissas(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2) {
    // 对齐两个尾数,不足的补0
    std::vector<int> res(mantissa1);
    std::vector<int> mantissa2Copy(mantissa2);
    if (mantissa2Copy.size() < res.size()) mantissa2Copy.insert(mantissa2Copy.begin(), res.size() - mantissa2Copy.size(), 0);
    if (mantissa2Copy.size() > res.size()) res.insert(res.begin(), mantissa2Copy.size() - res.size(), 0);

    // 从低位开始减
    for (int i = res.size() - 1; i >= 0; i--) {
        res[i] -= mantissa2Copy[i];
        if (res[i] < 0) {
            res[i] += 10;
            res[i - 1]--;
        }
    }

    // 去掉前导0
    while (res.size() > 1 && res[0] == 0) res.erase(res.begin());
    return res;
}

// 对尾数四舍五入
void Float::roundMantissa() {
    if (exponent == mantissa.size()) return;
    if (mantissa.size() - exponent <= 10) {
        mantissa.insert(mantissa.end(), 10 - (mantissa.size() - exponent), 0);
        return;
    }

    if (mantissa[exponent + 10] >= 5) {
        for (int i = exponent + 9; i >= 0; i--) {
            mantissa[i]++;
            if (mantissa[i] < 10) break;
            if (i == 0) {
                // 如果最高位也进位，则在最前面添加一个新的数字位
                mantissa.insert(mantissa.begin(), 1);
                exponent += 1; // 因为尾数变长了，指数也相应增加
            } else {
                mantissa[i] = 0; // 当前位变为0，继续向更高位进位
            }
        }
    }
    mantissa.resize(exponent + 10);
}