#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
        static const int kMax = 8;
        Contact contacts[kMax];
        int count;
        int nextIndex;

        static std::string trimToColumn(const std::string& s);

        int toInternal(int oneBasedIndex) const;    // 表示index→内部index
        
    public:
        PhoneBook();

        void addContact(const Contact& c);
        int size() const;
        
        void printSummary() const;

        bool printDetailByIndex(int oneBasedIndex) const;
};

#endif

