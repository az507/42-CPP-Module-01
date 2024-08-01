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

void	printZombieArr( int N, Zombie* zombieArr )
{
	if ( !zombieArr )
		std::cout << "zombieArr was not successfully created." << std::endl;
	else
		for ( int i = 0; i < N; ++i )
			zombieArr[i].announce();
}

int	main( void )
{
	srand(time(NULL));

	Zombie*	zombieArr;
	int	randomNum = rand() % ZOMBIE_MAX + 1;
	int	size;

	size = 0;
	zombieArr = zombieHorde( size, generateRandomStr(randomNum) );
	printZombieArr( size, zombieArr );
	delete [] zombieArr;

	size = std::numeric_limits<int>::min();
	zombieArr = zombieHorde( size, generateRandomStr(randomNum) );
	printZombieArr( size, zombieArr );
	delete [] zombieArr;

	size = 5;
	zombieArr = zombieHorde( size, "" );
	printZombieArr( size, zombieArr );
	delete [] zombieArr;

	size = randomNum;
	zombieArr = zombieHorde( size, generateRandomStr(randomNum) );
	printZombieArr( size, zombieArr );
	delete [] zombieArr;
}

