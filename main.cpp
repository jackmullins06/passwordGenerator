#include <iostream>
#include <random>
#include <chrono>

std::string password_gen(std::size_t length = 20) {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    std::mt19937 generator;
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> distribution(0, characters.size() - 1);

    std::string password;

    for (int i = 0; i < length; ++i) {
        password += characters[distribution(generator)];    
    }

    return password;
}

int main() {
    for(int i = 0; i < 5; ++i) {
        std::cout << password_gen() << "\n"<< std::endl;
    }
    return 0;
}
