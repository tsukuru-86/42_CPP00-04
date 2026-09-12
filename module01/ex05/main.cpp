#include "Harl.hpp"
#include <iostream>

int main(void) {
    Harl harl;

    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    const size_t levelCount = sizeof(levels) / sizeof(levels[0]);

    for (size_t i = 0; i < levelCount; ++i) {
        std::cout << "--- " << levels[i] << " ---" << std::endl;
        harl.complain(levels[i]);
        std::cout << std::endl;
    }

    return (0);
}
