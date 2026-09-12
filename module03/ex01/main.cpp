#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap defaultTrap;
    std::cout << "--- Construct ScavTrap s1 ---\n";
    ScavTrap s1("Serena");

    std::cout << "--- Copy-construct s2 from s1 ---\n";
    ScavTrap s2 = s1;

    std::cout << "--- Assign s3 = s1 ---\n";
    ScavTrap s3("Tmp");
    s3 = s1;

    std::cout << "--- Actions ---\n";
    s1.attack("dummy");
    s1.guardGate();
    s1.takeDamage(42);
    s1.beRepaired(10);

    std::cout << "--- Exhaust energy to show behavior ---\n";
    for (int i = 0; i < 60; ++i) s1.attack("target");

    std::cout << "--- Destructors will chain on exit ---\n";
    return 0;
}
