#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "[MateriaSource] Default ctor" << std::endl;
    for (int i = 0; i < 4; ++i) book[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "[MateriaSource] Copy ctor" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other.book[i]) book[i] = other.book[i]->clone();
        else book[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "[MateriaSource] Copy assign" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            if (book[i]) { delete book[i]; book[i] = 0; }
            if (other.book[i]) book[i] = other.book[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "[MateriaSource] Dtor" << std::endl;
    for (int i = 0; i < 4; ++i) if (book[i]) delete book[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!book[i]) {
            book[i] = m;
            std::cout << "[MateriaSource] Learned " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "[MateriaSource] Book full, discarding " << m->getType() << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (book[i] && book[i]->getType() == type) {
            return book[i]->clone();
        }
    }
    std::cout << "[MateriaSource] Unknown type '" << type << "'" << std::endl;
    return 0;
}

