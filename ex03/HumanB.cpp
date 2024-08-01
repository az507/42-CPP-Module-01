#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{

}

HumanB::~HumanB(void)
{

}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their ";

	if (_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "bare hands (not armed)" << std::endl;
}

void	HumanB::setWeapon(Weapon& weaponRef)
{
	this->_weapon = &weaponRef;
}

