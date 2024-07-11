#ifndef REPLACER_HPP
#define REPLACER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <filesystem>

class	Replacer
{
	private:
		std::string		_s1;
		std::string		_s2;
		std::string		_line;
		std::string		_filename;
	public:
		Replacer(std::string filename, std::string s1, std::string s2);
		std::string	getFileName(void);
		void		parseInput(void);
		void		openReadFile(void);
		void		rewriteFile(void);
};

#endif