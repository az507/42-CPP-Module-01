#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if ( N < 0 )
		return (NULL);

	Zombie	*zombieArr = new Zombie[N];

	for ( int i = 0; i < N; ++i )
		zombieArr[i].setName( name );
	
	return (zombieArr);
}
