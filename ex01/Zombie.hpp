#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <new>
# include <limits>
# include <ctime>
# include <cstdlib>

#define ZOMBIE_MAX 150

class	Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		void	setName( std::string );

		void	announce( void );

	private:
		std::string	name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif
