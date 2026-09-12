#include "ClapTrap.hpp"
#include <iostream>

bool ClapTrap::canAct_() const { return _hitPoints > 0 && _energyPoints > 0; }

void ClapTrap::logState_(const std::string& prefix) const {
    std::cout << prefix
              << " [name=" << _name
              << ", HP=" << _hitPoints
              << ", EN=" << _energyPoints
              << ", AD=" << _attackDamage << "]\n";
}

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << _name << "\n";
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap ctor called for " << _name << "\n";
    logState_(" created");
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy-ctor called for " << _name << "\n";
    logState_(" copied");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap copy-assign called for " << _name << "\n";
    logState_(" assigned");
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap dtor called for " << _name << "\n";
    logState_(" destroyed");
}

void ClapTrap::attack(const std::string& target) {
    if (!canAct_()) {
        std::cout << "ClapTrap " << _name
                  << " cannot attack (no HP or EN).\n";
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";
    logState_(" after attack");
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already at 0 HP. Further damage has no effect.\n";
        return;
    }
    if (amount >= _hitPoints) {
        _hitPoints = 0;
    } else {
        _hitPoints -= amount;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
    logState_(" after damage");
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!canAct_()) {
        std::cout << "ClapTrap " << _name
                  << " cannot be repaired (no HP or EN to act).\n";
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for "
              << amount << " hit points!\n";
    logState_(" after repair");
}
