#include "Harl.hpp"

int main()
{
	Harl		harl;
	std::string	level;
	std::cout << " _____________________________\n"
				 "|Please enter a number option:|\n"
				 "|-----------------------------|\n"
				 "|1 – DEBUG                    |\n"
				 "|2 – INFO                     |\n"
				 "|3 – WARINING                 |\n"
				 "|4 – ERROR                    |\n"
				 " -----------------------------" << std::endl;
	std::cin >> level;
	if (level.length() != 1 || level[0] > '4' || level[0] < '1')
	{
		std::cerr << "Error: You may only enter a number between 1–4" << std::endl;
		exit(1);
	}
	harl.complain(level);
	return 0;
}
