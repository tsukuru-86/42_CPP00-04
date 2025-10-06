#include <iostream>
#include <cctype>

int main(int ac, char **av) {
	if (ac == 1){ 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j] != '\0'; ++j) {
			unsigned char uc = static_cast<unsigned char>(av[i][j]);
			char upper = static_cast<char>(std::toupper(uc));
			std::cout << upper;
		}
	}

	std::cout << "\n";
	return 0;
}
