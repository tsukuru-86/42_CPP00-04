#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int N = 3;
	Zombie* horde = zombieHorde(N, "Horde");

	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		horde[i].announce();
	}
	delete[] horde;
	
	Zombie* single = zombieHorde(1, "Lonely");
	single[0].announce();
	delete[] single;
	
	return (0);
}
