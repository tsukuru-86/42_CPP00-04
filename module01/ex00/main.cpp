#include "Zombie.hpp"

int main(void)
{
	Zombie *heap_zombie = newZombie("Heap");
	heap_zombie->announce();

	randomChump("Stack");

	delete heap_zombie;

	return (0);
}
