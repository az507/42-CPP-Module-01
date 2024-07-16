#include "Zombie.hpp"

std::string	generateRandomStr( std::string::size_type strlen )
{
	static std::string const	charset
		= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string	randomStr;

	for ( std::string::size_type i = 0; i < strlen; ++i )
		randomStr += charset[rand() % charset.length()];

	return ( randomStr );
}

int	main( void )
{
	srand(time(NULL));
	int	randomNum = rand() % ZOMBIE_MAX + 1;
	int	i;

	Zombie	*zombiePtrs[randomNum];

	for ( i = 0; i < randomNum; ++i )
		zombiePtrs[i] = newZombie( generateRandomStr(rand() % randomNum + 1) );

	for ( i = 0; i < randomNum; ++i )
		zombiePtrs[i]->announce();

	for ( i = 0; i < randomNum; ++i )
		delete zombiePtrs[i];
	
	randomNum = rand() % ZOMBIE_MAX + 1;
	for ( i = 0; i < randomNum; ++i )
		randomChump( generateRandomStr(rand() % randomNum + 1) );
}

