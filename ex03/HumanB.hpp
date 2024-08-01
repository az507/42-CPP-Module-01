#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string);
		~HumanB(void);

		void	attack(void) const;

		void	setWeapon(Weapon&);

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif
