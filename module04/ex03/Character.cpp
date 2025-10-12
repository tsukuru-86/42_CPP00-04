#include "Character.hpp"

Character::Character(const std::string& n) : name(n), trashCount(0) {
    std::cout << "[Character] Ctor name=" << name << std::endl;
    for (int i = 0; i < 4; ++i) inventory[i] = 0;
    for (int i = 0; i < 100; ++i) trash[i] = 0;
}

Character::Character(const Character& other) : name(other.name), trashCount(0) {
    std::cout << "[Character] Copy ctor" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
    for (int i = 0; i < 100; ++i) trash[i] = 0;
}

Character& Character::operator=(const Character& other) {
    std::cout << "[Character] Copy assign" << std::endl;
    if (this != &other) {
        name = other.name;
        // delete current inventory
        for (int i = 0; i < 4; ++i) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = 0;
            }
        }
        // clone from other
        for (int i = 0; i < 4; ++i) {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
        // clear trash
        for (int i = 0; i < trashCount; ++i) {
            if (trash[i]) {
                delete trash[i];
                trash[i] = 0;
            }
        }
        trashCount = 0;
    }
    return *this;
}

Character::~Character() {
    std::cout << "[Character] Dtor name=" << name << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (inventory[i]) delete inventory[i];
    }
    for (int i = 0; i < trashCount; ++i) {
        if (trash[i]) delete trash[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << "[Character] Equipped slot " << i << " with " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "[Character] Inventory full, discarding materia " << m->getType() << std::endl;
    // Avoid leaks: store in trash to delete later
    if (trashCount < 100) trash[trashCount++] = m; else delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) return;
    if (!inventory[idx]) return;
    std::cout << "[Character] Unequipped slot " << idx << std::endl;
    // keep ownership to avoid leak
    if (trashCount < 100) trash[trashCount++] = inventory[idx];
    inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) return;
    if (inventory[idx])
        inventory[idx]->use(target);
}

