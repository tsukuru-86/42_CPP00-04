#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "--- Abstract AAnimal demo ---" << std::endl;

    // AAnimal a; // Uncommenting this should fail to compile (abstract)

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n--- Array and Deep Copy ---" << std::endl;
    const size_t N = 4;
    AAnimal* arr[N];
    for (size_t i = 0; i < N; ++i) {
        arr[i] = (i % 2 == 0) ? static_cast<AAnimal*>(new Dog()) : static_cast<AAnimal*>(new Cat());
    }
    for (size_t i = 0; i < N; ++i) {
        arr[i]->makeSound();
    }
    for (size_t i = 0; i < N; ++i) {
        delete arr[i];
    }

    std::cout << "\n--- Deep copy content check ---" << std::endl;
    Dog d1;
    d1.setIdea(0, "Bone");
    Dog d2 = d1; // copy construct
    d1.setIdea(0, "New Bone");
    std::cout << "d1 idea[0]: " << d1.getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2.getIdea(0) << std::endl; // should be old value

    Cat c1;
    c1.setIdea(0, "Fish");
    Cat c2;
    c2 = c1; // copy assign
    c1.setIdea(0, "Bird");
    std::cout << "c1 idea[0]: " << c1.getIdea(0) << std::endl;
    std::cout << "c2 idea[0]: " << c2.getIdea(0) << std::endl; // should be old value

    return 0;
}

