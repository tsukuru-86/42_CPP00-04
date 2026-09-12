#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    DiamondTrap defaultTrap;
    std::cout << "--- Construct DiamondTrap d1 ---\n";
    DiamondTrap d1("Diamondy");

    std::cout << "--- Show identity ---\n";
    d1.whoAmI();

    std::cout << "--- Attack via ScavTrap attack ---\n";
    d1.attack("dummy");
    d1.guardGate();
    d1.highFivesGuys();

    std::cout << "--- Copy-construct and assign ---\n";
    DiamondTrap d2 = d1;
    DiamondTrap d3("Tmp");
    d3 = d1;

    std::cout << "--- Show identity of copies ---\n";
    d2.whoAmI();
    d3.whoAmI();

    std::cout << "--- Test base behaviors ---\n";
    d1.takeDamage(42);
    d1.beRepaired(10);

    std::cout << "--- Destructors will chain on exit ---\n";
    return 0;
}
