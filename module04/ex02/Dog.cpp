#include "Dog.hpp"

Dog::Dog() : AAnimal(), brain(new Brain()) {
    this->type = "Dog";
    std::cout << "[Dog] Default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Dog] Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Copy assignment operator" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    return std::string();
}

