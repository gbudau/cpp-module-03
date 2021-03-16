#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

class ScavTrap {
	public:
						ScavTrap(std::string const & name);
						ScavTrap(ScavTrap const & src);
						~ScavTrap();
		ScavTrap &		operator=(ScavTrap const & rhs);
		void			rangedAttack(std::string const & target) const;
		void			meleeAttack(std::string const & target) const;
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			challengeNewcomer(std::string const & target);

	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_max_hit_points;
		unsigned int	_energy_points;
		unsigned int	_max_energy_points;
		unsigned int	_level;
		unsigned int	_melee_attack_damage;
		unsigned int	_ranged_attack_damage;
		unsigned int	_armor_damage_reduction;
		void			_print_quote(std::string const & quote) const;
		void			_print_info() const;
};

#endif  // SCAVTRAP_HPP_
