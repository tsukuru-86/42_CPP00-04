#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "[Ice] Default ctor" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "[Ice] Copy ctor" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "[Ice] Copy assign" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice() {
    std::cout << "[Ice] Dtor" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

