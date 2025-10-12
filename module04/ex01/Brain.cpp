#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] Default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Copy constructor" << std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] Copy assignment operator" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= 100) {
        std::cout << "[Brain] setIdea: index out of range" << std::endl;
        return;
    }
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        std::cout << "[Brain] getIdea: index out of range" << std::endl;
        return std::string();
    }
    return ideas[index];
}

