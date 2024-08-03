#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponRef) : _name(name), _weapon(weaponRef)
{

}

HumanA::~HumanA(void)
{

}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with " << this->_weapon.getType();
	std::cout << std::endl;
}

