#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

std::string generatePassword(std::size_t length = 16) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"$%&'()*+,-./:;<=>?@[\\]^_`{|}~,";
    std::mt19937 generator;
    std::random_device randomDevice;
    generator.seed(randomDevice());
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
    bool has_comma = false;

    for (std::size_t i = 0; i < password.size(); ++i) {
        char c = password[i];
        has_special = has_special || (c >= '!' && c <= '/' || c >= ':' && c <= '@' || c >= '[' && c <= '`' || c >= '{' && c <= '~');
        has_upper = has_upper || (c >= 'A' && c <= 'Z');
        has_lower = has_lower || (c >= 'a' && c <= 'z');
        has_number = has_number || (c >= '0' && c <= '9');
        has_comma = has_comma || (c == ',');
    }

    return has_special && has_upper && has_lower && has_number && has_comma;
}

int main(int argc, char** argv) {
    std::size_t passwordSize = 16; // Set default password length to 16

    if (argc >= 2) {
        try {
            passwordSize = std::stoi(argv[1]);
        } catch (std::exception& e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
            return 1;
        }
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
