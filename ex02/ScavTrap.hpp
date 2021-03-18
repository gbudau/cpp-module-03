#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
						ScavTrap(std::string const & name);
						ScavTrap(ScavTrap const & src);
						~ScavTrap();
		ScavTrap &		operator=(ScavTrap const & rhs);
		void			rangedAttack(std::string const & target) const;
		void			meleeAttack(std::string const & target) const;
		void			challengeNewcomer(std::string const & target);
};

#endif  // SCAVTRAP_HPP_
