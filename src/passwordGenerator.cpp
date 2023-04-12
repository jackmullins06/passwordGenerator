#include <stdexcept>
#include <string>
#include <vector>

#include "../include/passwordGenerator.h"
#include "../include/passwordValidation.h"

int main(int argc, char** argv) {
    std::size_t passwordSize = 16;

    if (argc >= 2) {
        try {
            passwordSize = std::stoi(argv[1]);
        } catch (std::exception& e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
            return 1;
        }
    }

    if (passwordSize < 16) {
        passwordSize = 16;
        std::cout << "Minimum password length: " << passwordSize << std::endl;
    }

    bool validPasswordGenerated = false;
    while (!validPasswordGenerated) {
        std::string password = generatePassword(passwordSize);
    
        if (validatePassword(password)) {
            std::cout << password << std::endl;
            validPasswordGenerated = true;
        }
    }
    return 0;
}

