#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

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