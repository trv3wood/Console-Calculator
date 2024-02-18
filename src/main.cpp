/*设计一个程序实现两个任意长的整数（包括正数和负数）、任意精度实数的乘除运算，其中以“-”号开头的为负数。

输入
第一行为一个数字n，表示待计算的组数

接下来为3n行内容，每组内容有3行，第一行表示做乘法还是除法，第二三行为两个数字，每次取一组内容来计算。

输出
共有n行，每行要换行,小数末尾不保留0,若小数点后都为0则不要小数点。

小数结果末尾最多保留10位小数，四舍五入，除数绝对值小于10(-6)则报ERROR

样例输入 Copy
3
*
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
/
1,234.567890123456789012
0.0000000000123
/
66,666,666,666,666,666,666,666,666,666,666.6666666666
-2
样例输出 Copy
152,415,787,532,388,367,504,953,515,625,666,819,450,083,828,733,757,049,236,500,533,455,762,536,198,787,501,905,199,875,019,052,100
ERROR
-33,333,333,333,333,333,333,333,333,333,333.3333333333*/
#include <iostream>
#include <string>
#include "ClassFloat.h"
#include "tryParse.h"
#include "calculate.h"

std::string numInput1 = "";
std::string numInput2 = "";
std::string operationInput = "";
Float n1, n2;

bool quitApp = false;

int main() {
    std::cout << "Console Calculator in C++ version 0.1.0" << std::endl;
    std::cout << "Type quit(q) to exit or run(r) to launch.\n"
    << "---------" << std::endl;
    std::string command = "";
    while (true) {
        std::cin >> command;
        if (command == "quit" || command == "q") {
            quitApp = true; break;
        } else if (command == "run" || command == "r") break; 
        else std::cout << "Unknown command. Please try again: \n";
    }

    while (!quitApp) {
        std::cout << "Choose an operator from the following list:\n"
        << "add(+)\tsubtract(-)\tmultiply(*)\tdivide(/)\n";

        while (true) {
            std::cin >> operationInput;
            if (isValidOperator(operationInput)) {
                break;
            } else if (operationInput == "quit" || operationInput == "q") {
                goto codeQuit;
            } else {
                std::cout << "Invalid input. Please enter an operator.\n";
            }
        }

        std::cout << "Type the first number:" << std::endl;
        while (true) {
            std::cin >> numInput1;
            if (isValidNumber(numInput1)) {
                break;
            } else if (numInput1 == "quit" || numInput1 == "q") {
                goto codeQuit;
            } else {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }

        std::cout << "Type the second number:" << std::endl;
        while (true) {
            std::cin >> numInput2;
            if (isValidNumber(numInput2)) {
                break;
            } else if (numInput2 == "quit" || numInput2 == "q") {
                goto codeQuit;
            } else {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }

        n1 = numInput1;
        n2 = numInput2;
        std::cout << "Result: " << calculate(n1, n2, operationInput) << std::endl;

        std::cout << "Continue? (Y/n)\n";
        char confirm;
        while (true) {
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') break;
            else if (confirm == 'n' || confirm == 'N') goto codeQuit;
            else std::cout << "Unknown command. Please try again:\n";
        }
    }
    codeQuit:
    std::cout << "Aborted" << std::endl;
}
