#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- Correct Polymorphism ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound(); // cat sound
    j->makeSound(); // dog sound
    meta->makeSound(); // generic animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- Wrong Polymorphism ---" << std::endl;
    const WrongAnimal* w = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << wc->getType() << std::endl;
    wc->makeSound(); // will output the WrongAnimal sound due to non-virtual
    w->makeSound();
    delete w;
    delete wc; // base dtor not virtual; no dynamic member, safe here but illustrates the issue

    return 0;
}

