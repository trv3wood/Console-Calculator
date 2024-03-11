#include "usrInteraction.h"
#include <iostream>

bool usrInteraction(std::string& usrInput, bool(*isValidFunc)(const std::string&), const std::string& errorMessage) {
    bool quitApp = false;
    while (true) {
        std::cin >> usrInput;
        if (isValidFunc(usrInput)) {
            return quitApp;
        } else if (usrInput == "quit" || usrInput == "q") {
            quitApp = true;
            return quitApp;
        } else {
            std::cout << errorMessage << '\n';
        }
    }
}