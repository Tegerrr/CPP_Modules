#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		harl;

	if (!argv[1] || argc != 2)
	{
		std::cerr << "Usage: ./harlFilter \"OPTION\"" << std::endl;
		exit(1);
	}
	harl.complain(argv[1]);
	return 0;
}
