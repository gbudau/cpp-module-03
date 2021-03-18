#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_
#include <iostream>
#include <string>

class ClapTrap {
 public:
						ClapTrap(std::string const & type,
								std::string const & name,
								unsigned int hit_points,
								unsigned int max_hit_points,
								unsigned int energy_points,
								unsigned int max_energy_points,
								unsigned int level,
								unsigned int melee_attack_damage,
								unsigned int ranged_attack_damage,
								unsigned int armor_damage_reduction);
						ClapTrap(ClapTrap const & src);
						~ClapTrap();
	ClapTrap &			operator=(ClapTrap const & rhs);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	std::string const &	getType() const;
	std::string const &	getName() const;
	unsigned int		getHitPoints() const;
	unsigned int		getMaxHitPoints() const;
	unsigned int		getEnergyPoints() const;
	unsigned int		getMaxEnergyPoints() const;
	unsigned int		getLevel() const;
	unsigned int		getMeleeAttackDamage() const;
	unsigned int		getRangedAttackDamage() const;
	unsigned int		getArmorDamageReduction() const;

 protected:
	void				setType(std::string const & type);
	void				setName(std::string const & name);
	void				setHitPoints(unsigned int hit_points);
	void				setMaxHitPoints(unsigned int max_hit_points);
	void				setEnergyPoints(unsigned int energy_points);
	void				setMaxEnergyPoints(unsigned int max_energy_points);
	void				setLevel(unsigned int level);
	void				setMeleeAttackDamage(unsigned int melee_attack_damage);
	void				setRangedAttackDamage(
											unsigned int ranged_attack_damage);
	void				setArmorDamageReduction(
										unsigned int armor_damage_reduction);
	void				_print_quote(std::string const & quote) const;
	void				_print_info() const;

 private:
	std::string		_type;
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

#endif  // CLAPTRAP_HPP_
