#ifndef NINJATRAP_HPP_
#define NINJATRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap {
 public:
					NinjaTrap(std::string const & name);
					NinjaTrap(NinjaTrap const & src);
					~NinjaTrap();
	NinjaTrap &		operator=(NinjaTrap const & rhs);
	void			rangedAttack(std::string const & target) const;
	void			meleeAttack(std::string const & target) const;
	void			ninjaShoebox(ClapTrap const & claptrap);
	void			ninjaShoebox(FragTrap const & fragtrap);
	void			ninjaShoebox(ScavTrap const & scavtrap);
	void			ninjaShoebox(NinjaTrap const & ninjatrap);
};

#endif  // NINJATRAP_HPP_
