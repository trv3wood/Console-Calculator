#include <iostream>
#include <string>
#include "ClassFloat.h"
#include "tryParse.h"
#include "calculate.h"
#include "usrInteraction.h"

std::string numInput1 = "";
std::string numInput2 = "";
std::string operationInput = "";
Float n1, n2;

bool runningApp = true;

int main() {
    std::cout << "Console Calculator in C++ version 0.1.0" << std::endl;
    std::cout << "Type quit(q) to exit or run(r) to launch the program.\n"
    << "---------" << std::endl;
    while (true) {
        std::string command = "";
        std::cin >> command;
        if (command == "quit" || command == "q") {
            runningApp = false; break;
        } else if (command == "run" || command == "r") break; 
        else std::cout << "Unknown command. Please try again: \n";
    }

    while (runningApp) {

        std::cout << "Choose an operator from the following list:\n"
        << "add(+)\tsubtract(-)\tmultiply(*)\tdivide(/)\n";
        if (usrInteraction(operationInput, isValidOperator, "Invalid input. Please enter an operator.")) {
            goto codeQuit;
        }

        std::cout << "Type the first number:" << std::endl;
        if (usrInteraction(numInput1, isValidNumber, "Invalid input. Please enter a number.")) {
            goto codeQuit;
        }

        std::cout << "Type the second number:" << std::endl;
        if (usrInteraction(numInput2, isValidNumber, "Invalid input. Please enter a number.")) {
            goto codeQuit;
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
