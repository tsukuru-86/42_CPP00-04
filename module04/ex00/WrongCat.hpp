#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat(); // Not virtual in base

    void makeSound() const; // This won't be called via WrongAnimal*
};

#endif // WRONGCAT_HPP

