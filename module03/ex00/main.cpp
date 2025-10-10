#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");
    ClapTrap b = a;            // copy ctor
    ClapTrap c("Charlie");
    c = a;                     // copy assignment

    a.attack("target-dummy");
    a.takeDamage(5);
    a.beRepaired(3);

    // 枯渇時の動作
    for (int i = 0; i < 12; ++i) a.attack("dummy"); // EN切れ確認
    a.beRepaired(10); // EN不足で不可
    a.takeDamage(100); // 0まで落ちる
    a.attack("dummy"); // HP=0で不可
    a.beRepaired(1);   // HP=0 & EN=0 →不可（行動できない）

    return 0;
}
