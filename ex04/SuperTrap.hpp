#ifndef SUPERTRAP_HPP_
#define SUPERTRAP_HPP_
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : public FragTrap, public NinjaTrap {
 public:
				SuperTrap(std::string const & name);
				SuperTrap(SuperTrap const & src);
				~SuperTrap();
	SuperTrap &	operator=(SuperTrap const & rhs);
	void		rangedAttack(std::string const & target) const;
	void		meleeAttack(std::string const & target) const;
};

#endif  // SUPERTRAP_HPP_
