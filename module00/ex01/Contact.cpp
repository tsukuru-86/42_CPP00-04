#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string& s)   { firstName    = s; }
void Contact::setLastName(const std::string& s)    { lastName     = s; }
void Contact::setNickname(const std::string& s)    { nickname     = s; }
void Contact::setPhoneNumber(const std::string& s) { phoneNumber  = s; }
void Contact::setDarkestSecret(const std::string& s){ darkestSecret = s; }

const std::string& Contact::getFirstName()   const { return firstName; }
const std::string& Contact::getLastName()    const { return lastName; }
const std::string& Contact::getNickname()    const { return nickname; }
const std::string& Contact::getPhoneNumber() const { return phoneNumber; }
const std::string& Contact::getDarkestSecret() const { return darkestSecret; }

bool Contact::isComplete() const {
    return !firstName.empty() && !lastName.empty() && !nickname.empty()
        && !phoneNumber.empty() && !darkestSecret.empty();
}

