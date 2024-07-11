#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
{
	_filename = filename;
	_s1 = s1;
	_s2 = s2;
}

void	Replacer::parseInput(void)
{

	if (_filename.empty() || _s1.empty() || _s2.empty())
	{
		std::cerr << "! Error: empty arguments !" << std::endl;
		exit(1);
	}
}

void	Replacer::openReadFile(void)
{
	std::ifstream	inputFile(_filename);

	if (!inputFile)
	{
		std::cerr << "! Could not open " << _filename << " file !" << std::endl;
		exit(1);
	}
	while (std::getline(inputFile, _line, '\0'));
	if (_line.empty())
	{
		std::cerr << "! File " << _filename << " is empty !" << std::endl;
		exit(1);
	}
	inputFile.close();
}

void	Replacer::rewriteFile(void)
{
	std::fstream	outputFile(_filename + ".replace", std::fstream::out);
	std::string		rewrite_to;
	size_t			pos = _line.find(_s1);
	size_t			prev_pos = 0;
	std::string		temp;

	if (!outputFile.is_open() || !outputFile || outputFile.good() == 0)
	{
		std::cout << "! Error: Couldn't open, read, or write to " << _filename << ".replace file !" << std::endl;
		exit(1);
	}
	while (pos != std::string::npos)
	{
		rewrite_to += _line.substr(prev_pos, pos - prev_pos);
		rewrite_to += _s2;
		prev_pos = pos + _s1.length();
		pos = _line.find(_s1, pos + _s2.length());
	}
	if (_line[prev_pos])
		rewrite_to += _line.substr(prev_pos, _line.length() - prev_pos);
	outputFile << rewrite_to;
	outputFile.close();
}
