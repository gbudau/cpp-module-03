#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
					FragTrap(std::string const & name);
					FragTrap(FragTrap const & src);
					~FragTrap();
	FragTrap &		operator=(FragTrap const & rhs);
	void			rangedAttack(std::string const & target) const;
	void			meleeAttack(std::string const & target) const;
	void			vaulthunter_dot_exe(std::string const & target);
};

#endif  // FRAGTRAP_HPP_
