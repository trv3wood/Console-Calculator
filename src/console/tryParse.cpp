#include <string>
bool isValidOperator(const std::string& op) {
    return (op == "+") || (op == "-") || (op == "*") || (op == "/");
}

bool isValidNumber(const std::string& num) {
    int dotPos = num.find('.');
    if (num.empty()) return false;

    int start = 0;
    if (num[0] == '-' || num[0] == '+') start = 1;

    if (dotPos == std::string::npos) {
        for (int i = start; i < num.length(); i++) {
            if (num[i] == ',') continue;
            int t = num[i] - '0';
            if (t < 0 || t > 9) return false;
        }
    } else {
        if (dotPos < 1 || dotPos + 1 == num.length()) return false;
        for (int i = start; i < dotPos; i++) {
            if (num[i] == ',') continue;
            int t = num[i] - '0';
            if (t < 0 || t > 9) return false;
        }
        for (int i = dotPos + 1; i < num.length(); i++) {
            int t = num[i] - '0';
            if (t < 0 || t > 9) return false;
        }
    }
    return true;
}