#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

void Harl::debug() {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string &level) {
    typedef void (Harl::*Action)();
    struct LevelAction {
        const char *name;
        Action action;
    };

    static const LevelAction actions[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    const size_t count = sizeof(actions) / sizeof(actions[0]);
    for (size_t i = 0; i < count; ++i) {
        if (level == actions[i].name) {
            (this->*actions[i].action)();
            return;
        }
    }

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
