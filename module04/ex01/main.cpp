#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "--- Array of Animals (Dogs/Cats) ---" << std::endl;
    const size_t N = 6;
    Animal* animals[N];

    for (size_t i = 0; i < N; ++i) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (size_t i = 0; i < N; ++i) {
        animals[i]->makeSound();
    }

    for (size_t i = 0; i < N; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- Deep Copy Test (Dog) ---" << std::endl;
    Dog a;
    a.setIdea(0, "Chase cats");
    a.setIdea(1, "Fetch ball");

    Dog b = a; // copy construct
    a.setIdea(0, "Sleep all day");

    std::cout << "Dog a idea[0]: " << a.getIdea(0) << std::endl;
    std::cout << "Dog b idea[0]: " << b.getIdea(0) << std::endl; // should be original

    std::cout << "\n--- Deep Copy Test (Cat) ---" << std::endl;
    Cat c1;
    c1.setIdea(0, "Ignore humans");
    Cat c2;
    c2 = c1; // copy assign
    c1.setIdea(0, "Knock things off");
    std::cout << "Cat c1 idea[0]: " << c1.getIdea(0) << std::endl;
    std::cout << "Cat c2 idea[0]: " << c2.getIdea(0) << std::endl; // should be original

    std::cout << "\n--- Simple Leak Check Pair ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not leak
    delete i;

    return 0;
}

