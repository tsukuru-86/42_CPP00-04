#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap();

ClapTrap(const ClapTrap& other);

ClapTrap& operator=(const ClapTrap& other);

ClapTrap~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

void attack(const std::string& target);
void takeDamage(unsigned int amount);
dldっld