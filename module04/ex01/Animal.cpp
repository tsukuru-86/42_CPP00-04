#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] Default constructor" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Copy assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] ...generic animal sound..." << std::endl;
}

