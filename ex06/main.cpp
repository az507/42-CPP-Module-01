#include "Harl.hpp"

const std::string 	table[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

enum	HarlLevel
{
	debug = 0,
	info,
	warning,
	error,
};

int	computeNum( std::string level )
{
	int	i;
	bool	foundEntry = false;

	for (i = 0; !foundEntry && i < 5; ++i)
		foundEntry = ::table[i] == level;
	
	return (i - 1);
}

int	main(int argc, char *argv[])
{
	std::string	str;
	Harl		harl;

	if (argc < 2)
		str = "";
	else
		str = argv[1];
	switch (computeNum(str))
	{
		case debug:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout.put('\n');
		case info:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout.put('\n');
		case warning:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout.put('\n');
		case error:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout.put('\n');
			break ;
		default:
			harl.complain(argv[i]);
	}
	std::cout.flush();
}

