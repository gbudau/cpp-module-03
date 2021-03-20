#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
					FragTrap(std::string const & name);
					FragTrap(FragTrap const & src);
					~FragTrap();
	FragTrap &		operator=(FragTrap const & rhs);
	void			rangedAttack(std::string const & target) const;
	void			meleeAttack(std::string const & target) const;
	void			vaulthunter_dot_exe(std::string const & target);

 protected:
	unsigned int	getDefaultHitPoints() const;
	unsigned int	getDefaultMaxHitPoints() const;
	unsigned int	getDefaultEnergyPoints() const;
	unsigned int	getDefaultMaxEnergyPoints() const;
	unsigned int	getDefaultLevel() const;
	unsigned int	getDefaultMeleeAttackDamage() const;
	unsigned int	getDefaultRangedAttackDamage() const;
	unsigned int	getDefaultArmorDamageReduction() const;

 private:
	static const unsigned int	_default_hit_points;
	static const unsigned int	_default_max_hit_points;
	static const unsigned int 	_default_energy_points;
	static const unsigned int 	_default_max_energy_points;
	static const unsigned int 	_default_level;
	static const unsigned int 	_default_melee_attack_damage;
	static const unsigned int 	_default_ranged_attack_damage;
	static const unsigned int 	_default_armor_damage_reduction;
};

#endif  // FRAGTRAP_HPP_
