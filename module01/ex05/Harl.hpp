#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
    Harl();
    void complain(const std::string &level);

private:
    void debug();
    void info();
    void warning();
    void error();
};

#endif
