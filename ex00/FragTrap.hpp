#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

class FragTrap {
	public:
						FragTrap(std::string const & name);
						FragTrap(FragTrap const & src);
						~FragTrap();
		FragTrap &		operator=(FragTrap const & rhs);
		void			rangedAttack(std::string const & target) const;
		void			meleeAttack(std::string const & target) const;
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			vaulthunter_dot_exe(std::string const & target);
		void 			displayStats() const;

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
};

#endif  // FRAGTRAP_HPP_
