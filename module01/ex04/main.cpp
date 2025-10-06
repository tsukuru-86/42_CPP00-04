#include <iostream>
#include <fstream>
#include <string>

typedef std::string str;

void    replaceInLine(str &line, const str &s1, const str &s2)
{
    size_t pos = 0;

    while ((pos = line.find(s1, pos)) != str::npos)
    {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s2.length();
    }
}

int main(int ac, char **av)
{
	if (ac != 4 || !av[1][0] || !av[2][0])
	{
		std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	str filename = av[1];
	str outfile = filename + ".replace";
	std::ifstream input(filename);
	std::ofstream output(outfile);

    if (!input.is_open())
    {
        std::cout << "Error: Cannot open input file" << std::endl;
        return 1;
    }

	str line;
	while (std::getline(input, line))
	{
		replaceInLine(line, av[2], av[3]);
		output << line;
		if (!input.eof())
			output << std::endl;
	}
	input.close();
	output.close();
	return 0;
}
