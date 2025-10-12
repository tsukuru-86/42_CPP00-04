#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "[Cure] Default ctor" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "[Cure] Copy ctor" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "[Cure] Copy assign" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "[Cure] Dtor" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

