#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "[AAnimal] Default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "[AAnimal] Copy constructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "[AAnimal] Copy assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "[AAnimal] Destructor" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}

