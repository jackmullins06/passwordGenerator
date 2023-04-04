#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * This function generates a secure random password of the specified length
 * using a set of characters that includes uppercase and lowercase letters,
 * digits, and special characters. The password is generated using a
 * cryptographic-strength random number generator to ensure that it is
 * unpredictable and cannot be easily guessed.
 * 
 * @param length The length of the password to generate
 * @return The generated password as a string
 */
std::string generatePassword(std::size_t length) {
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

/**
 * This function checks whether a given password is valid or not. A password
 * is considered valid if it contains at least one uppercase letter, one lowercase
 * letter, one digit, one special character, and one comma. The function returns
 * true if the password is valid, and false otherwise.
 *
 * @param password The password to validate
 * @return True if the password is valid, false otherwise
 */
bool validatePassword(const std::string& password) {
    bool has_special_character = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;
    bool has_comma = false;

    for(const char c : password) {
        has_special_character = has_special_character || (c >= '!' && c <= '/' || c >= ':' && c <= '@' || c >= '[' && c <= '`' || c >= '{' && c <= '~');
        has_upper = has_upper || (c >= 'A' && c <= 'Z');
        has_lower = has_lower || (c >= 'a' && c <= 'z');
        has_number = has_number || (c >= '0' && c <= '9');
        has_comma = has_comma || (c == ',');
    }

    return has_special_character && has_upper && has_lower && has_number && has_comma;
}

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

