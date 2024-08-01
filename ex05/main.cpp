#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;

	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("akjfdkawljfajfqj");
	harl.complain("");

	std::cout << "\n\n\n";

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");

	std::cout << "\n\n\n";

	harl.complain(std::string());
	harl.complain("DEBUG");
	harl.complain("\0");

	std::cout << "\n\n\n";

	while (*(++argv))
		harl.complain(static_cast<std::string>(*argv));
}

