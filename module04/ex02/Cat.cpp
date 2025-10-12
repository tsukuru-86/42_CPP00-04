#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain()) {
    this->type = "Cat";
    std::cout << "[Cat] Default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Cat] Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Copy assignment operator" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    return std::string();
}

