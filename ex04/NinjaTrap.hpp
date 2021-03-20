#ifndef NINJATRAP_HPP_
#define NINJATRAP_HPP_
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap {
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

#endif  // NINJATRAP_HPP_
