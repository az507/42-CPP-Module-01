#include "Zombie.hpp"

Zombie::Zombie( std::string zombieName ) : name( zombieName )
{

}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name << " has been destroyed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

