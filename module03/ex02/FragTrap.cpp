#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("DefaultFragTrap") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called for " << _name << "\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap ctor called for " << _name << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy-ctor called for " << _name << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap copy-assign called for " << _name << "\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap dtor called for " << _name << "\n";
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "FragTrap " << _name
                  << " cannot attack (no HP or EN).\n";
        return;
    }
    --_energyPoints;
    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << ": High fives, guys!!! \\o/\n";
}
