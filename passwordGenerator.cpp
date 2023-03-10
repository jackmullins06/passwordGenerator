#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

std::string password_gen(std::size_t length = 16) {
    if (length < 16) {
        throw std::invalid_argument("Password length must be at least 16 characters long");
    }

    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#€£$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    std::mt19937 generator;
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> distribution(0, characters.size() - 1);

    std::string password;

    bool has_special = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;

    while (!has_special || !has_upper || !has_lower || !has_number) {
        password.clear();

        has_special = false;
        has_upper = false;
        has_lower = false;
        has_number = false;

        for (std::size_t i = 0; i < length; ++i) {
            char c = characters[distribution(generator)];
            password += c;
            has_special = has_special || (c >= '!' && c <= '/' || c >= ':' && c <= '@' || c >= '[' && c <= '`' || c >= '{' && c <= '~');
            has_upper = has_upper || (c >= 'A' && c <= 'Z');
            has_lower = has_lower || (c >= 'a' && c <= 'z');
            has_number = has_number || (c >= '0' && c <= '9');
        }
    }
    return password;
}


/**
 * The main function prints out 5 different randomly generated passwords
 * to the console. */
int main() {
    for(int i = 0; i < 5; i++) {
       std::cout << password_gen(20) << std::endl;
    }
    return 0;
}