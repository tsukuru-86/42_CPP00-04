#include <iostream>
#include <fstream>
#include <string>

typedef std::string str;

static bool copyAndReplace(std::ifstream &input, std::ofstream &output,
	const str &s1, const str &s2)
{
	str content;
	char character;

	while (input.get(character))
		content += character;
	if (!input.eof())
		return (false);
	str::size_type start = 0;
	str::size_type match;
	while ((match = content.find(s1, start)) != str::npos)
	{
		output << content.substr(start, match - start) << s2;
		start = match + s1.length();
	}
	output << content.substr(start);
	return (output.good());
}

int main(int ac, char **av)
{
	if (ac != 4 || !av[1][0] || !av[2][0])
	{
		std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	const str filename(av[1]);
	const str outfile(filename + ".replace");
	std::ifstream input(filename.c_str(), std::ios::in | std::ios::binary);
	if (!input.is_open())
	{
		std::cout << "Error: cannot open input file" << std::endl;
		return (1);
	}
	std::ofstream output(outfile.c_str(), std::ios::out | std::ios::binary);
	if (!output.is_open())
	{
		std::cout << "Error: cannot open output file" << std::endl;
		return (1);
	}
	if (!copyAndReplace(input, output, av[2], av[3]))
	{
		std::cout << "Error: file operation failed" << std::endl;
		return (1);
	}
	output.close();
	if (output.fail())
	{
		std::cout << "Error: cannot finalize output file" << std::endl;
		return (1);
	}
	return (0);
}
