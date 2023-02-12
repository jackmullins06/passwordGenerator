#include <iostream>
#include <random>
#include <chrono>

/**
 * This function returns a 20 character randomly generated string that has 
 * been generated using a Mersenne Twister pseudo-random generator, that 
 * that could be used as a password. */
std::string password_gen(std::size_t length = 20) {
    if(length < 1) {
       std::cout <<  "" << std::endl;
    }
    
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#€£$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    std::mt19937 generator;
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> distribution(0, characters.size() - 1);

    std::string password;

    for (int i = 0; i < length; ++i) {
        password += characters[distribution(generator)];    
    }

    return password;
}

/**
 * The main function prints out 5 different randomly generated passwords
 * to the console. */
int main() {
    for(int i = 0; i < 5; i++) {
       std::cout << password_gen(35) << "\n" << std::endl;
    }
    return 0;
}
