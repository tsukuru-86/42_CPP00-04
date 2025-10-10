#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    // Set desired stats: HP from FragTrap (100), EN from ScavTrap (50), AD from FragTrap (30)
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap ctor called for " << _name << " (ClapTrap name: " << ClapTrap::_name << ")\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy-ctor called for " << _name << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        // Assign through each base to keep ClapTrap state consistent
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap copy-assign called for " << _name << "\n";
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap dtor called for " << _name << " (ClapTrap name: " << ClapTrap::_name << ")\n";
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name
              << ", ClapTrap name: " << ClapTrap::_name << "\n";
}
