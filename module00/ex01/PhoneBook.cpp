#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

void PhoneBook::addContact(const Contact& c) {
    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % kMax;
    if (count < kMax) count++;
}

int PhoneBook::size() const {return count; }

std::string PhoneBook::trimToColumn(const std::string& s) {
    if (s.size() >  10) return s.substr(0, 9) + ".";
    return s;
}

void PhoneBook::printSummary() const {
    std::cout << "---------------------------------------------\n";
    std::cout << "|" << std::setw(10) << "index"
              << "|" << std::setw(10) << "first name"
              << "|" << std::setw(10) << "last name"
              << "|" << std::setw(10) << "nickname"
              << "|\n";
    std::cout << "---------------------------------------------\n";

    int start = (count == kMax) ? nextIndex : 0;
    for (int i = 0; i < count; ++i) {
        int idx = (start + i) % kMax;
        std::cout << "|" << std::setw(10) << (i + 1)
                  << "|" << std::setw(10) << trimToColumn(contacts[idx].getFirstName())
                  << "|" << std::setw(10) << trimToColumn(contacts[idx].getLastName())
                  << "|" << std::setw(10) << trimToColumn(contacts[idx].getNickname())
                  << "|\n";
    }
    std::cout << "---------------------------------------------\n";
}

int PhoneBook::toInternal(int oneBasedIndex) const {
    if (count == 0) return -1;
    if (oneBasedIndex < 1 || oneBasedIndex > count) return -1;

    int start = (count == kMax) ? nextIndex : 0;
    return (start + oneBasedIndex - 1) % kMax;
}

bool PhoneBook::printDetailByIndex(int oneBasedIndex) const {
    if (oneBasedIndex < 1 || oneBasedIndex > count)
        return false;

    int start = (count == kMax) ? nextIndex : 0;
    int internal = (start + (oneBasedIndex - 1)) % kMax;
    const Contact& c = contacts[internal];

    std::cout << "First name: " << c.getFirstName() << '\n'
              << "Last name: " << c.getLastName() << '\n'
              << "Nickname: " << c.getNickname() << '\n'
              << "Phone number: " << c.getPhoneNumber() << '\n'
              << "Darkest secret: " << c.getDarkestSecret() << '\n';
    return true;
}

