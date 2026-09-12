#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstddef>
#include <string>

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void announce(void);
		void setName(std::string name);

	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
