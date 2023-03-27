#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

std::size_t promptForLength() {
    std::size_t passwordLength;

    while(true) {
        std::cout << "Please enter your desired password length (minimum 16 characters): ";
        std::string input;
        std::getline(std::cin, input);

        try {
            passwordLength = std::stoi(input);
        } catch (const std::exception& e) {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
            continue;
        }

        if(passwordLength >= 16) {
            return passwordLength;
        }

        std::cout << "Invalid input. Password length must be at least 16 characters." << std::endl;
    }
}

std::string generatePassword(std::size_t length = 16) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    std::mt19937 generator;
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> distribution(0, characters.size() - 1);

    std::string password;

    for (std::size_t i = 0; i < length; ++i) {
            password += characters[distribution(generator)];
    }
    return password;
}

bool validatePassword(const std::string& password) {
    bool has_special = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;

    for (std::size_t i = 0; i < password.size(); ++i) {
        char c = password[i];
        has_special = has_special || (c >= '!' && c <= '/' || c >= ':' && c <= '@' || c >= '[' && c <= '`' || c >= '{' && c <= '~');
        has_upper = has_upper || (c >= 'A' && c <= 'Z');
        has_lower = has_lower || (c >= 'a' && c <= 'z');
        has_number = has_number || (c >= '0' && c <= '9');
    }

    return has_special && has_upper && has_lower && has_number;
}


int main() {
    std::size_t passwordSize = promptForLength();
    std::string password = generatePassword(passwordSize);

    if (validatePassword(password)) {
        std::cout << "Generated password is valid: " << password << std::endl;
    } else {
        std::cout << "Generated password is not valid: " << password << std::endl;
    }

    return 0;
}