#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap scav("Serena");
    scav.attack("dummy");
    scav.guardGate();

    FragTrap defaultTrap;
    std::cout << "--- Construct FragTrap f1 ---\n";
    FragTrap f1("Franny");

    std::cout << "--- Copy-construct f2 from f1 ---\n";
    FragTrap f2 = f1;

    std::cout << "--- Assign f3 = f1 ---\n";
    FragTrap f3("Tmp");
    f3 = f1;

    std::cout << "--- Actions ---\n";
    f1.attack("dummy");
    f1.highFivesGuys();
    f1.takeDamage(35);
    f1.beRepaired(20);

    std::cout << "--- Exhaust energy to show behavior ---\n";
    for (int i = 0; i < 105; ++i) f1.attack("target");

    std::cout << "--- Destructors will chain on exit ---\n";
    return 0;
}
