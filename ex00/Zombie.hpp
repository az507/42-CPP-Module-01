#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <new>
# include <ctime>
# include <cstdlib>

#define ZOMBIE_MAX 100

class	Zombie
{
	public:
		Zombie( std::string );
		~Zombie( void );

		void	announce( void );

	private:
		std::string	name;
};

Zombie*	newZombie( std::string );
void	randomChump( std::string );

#endif
