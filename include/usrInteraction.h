#include <string>
bool usrInteraction(std::string& usrInput, bool(*isValidFunc)(const std::string&), const std::string& errorMessage);