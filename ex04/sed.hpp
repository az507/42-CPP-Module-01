#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <cstring>

struct	params
{
	std::ifstream*	infile;
	std::ofstream*	outfile;

	std::string*	strbuf;
	char*		buffer;

	std::string	str1;
	std::string	str2;
};

void		cleanupHandler(struct params* params);
struct params*	inputHandler(int argc, char *argv[]);
int		infileSizeHandler(struct params* params);

#endif
