#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	setType(weaponType);
}

Weapon::~Weapon(void)
{

}

std::string const&	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string weaponType)
{
	this->type = weaponType;
}

