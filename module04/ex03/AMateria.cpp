#include "AMateria.hpp"

AMateria::AMateria(std::string const & t) : type(t) {
    std::cout << "[AMateria] Ctor type=" << type << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "[AMateria] Copy ctor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "[AMateria] Copy assign" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "[AMateria] Dtor type=" << type << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "[AMateria] used on " << target.getName() << std::endl;
}

