#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{

}

HumanB::~HumanB(void)
{
	unsetWeapon();
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their ";

	if (_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "bare hands (not armed)" << std::endl;
}

void	HumanB::unsetWeapon(void)
{
	delete _weapon;
	_weapon = NULL;
}

void	HumanB::setWeapon(Weapon weaponRef)
{
	unsetWeapon();
	this->_weapon = new Weapon(weaponRef.getType());
}

