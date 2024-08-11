#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "! Error: wrong amount of argumnets !" << std::endl;
		exit(1);
	}
	Replacer	Sed(argv[1], argv[2], argv[3]);
	Sed.parseInput();
	Sed.openReadFile();
	Sed.rewriteFile();
	return 0;
}
