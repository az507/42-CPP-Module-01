#include "Harl.hpp"

Harl::Harl(void)
{
	this->_fnptrs[0] = &Harl::debug;
	this->_fnptrs[1] = &Harl::info;
	this->_fnptrs[2] = &Harl::warning;
	this->_fnptrs[3] = &Harl::error;
	this->_fnptrs[4] = &Harl::unclassified;
}

Harl::~Harl( void )
{

}

static int	computeNum( std::string level )
{
	int	i;
	bool	foundEntry = false;
	static const std::string table[5] = { "DEBUG", "INFO", "WARNING", "ERROR", "" };

	for (i = 0; !foundEntry && i < 5; ++i)
		foundEntry = table[i] == level;
	
	return (i - 1);
}

void	Harl::complain( std::string level )
{
	(this->*_fnptrs[ computeNum(level) ])();
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle";
	std::cout << "-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't ";
	std::cout << "put enough bacon in my burger! If you did, I wouldn't be asking for ";
	std::cout << "more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been ";
	std::cout << "coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::unclassified(void)
{
	std::cout << "Unclassified type of comment." << std::endl;
}

