#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name)
	: _name(name), _hit_points(100), _max_hit_points(100), _energy_points(100),
	_max_energy_points(100), _level(1), _melee_attack_damage(30),
	_ranged_attack_damage(20), _armor_damage_reduction(5) {
	std::cout << "FR4G-TP " <<  this->_name <<
		": Let's get this party started!\n";
	return ;
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
	std::cout << "FR4G-TP " <<  this->_name <<
		": Oh, hello there!\n";
}

FragTrap::~FragTrap() {
	std::cout << "FR4G-TP " <<  this->_name <<
		": Ooh yeah, watch me! Watch me go!\n";
	return;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_max_hit_points = rhs._max_hit_points;
		this->_energy_points = rhs._energy_points;
		this->_max_energy_points = rhs._max_energy_points;
		this->_level = rhs._level;
		this->_melee_attack_damage = rhs._melee_attack_damage;
		this->_ranged_attack_damage = rhs._ranged_attack_damage;
		this->_armor_damage_reduction = rhs._armor_damage_reduction;
	}
	return *this;
}

void		FragTrap::rangedAttack(std::string const & target) const {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target <<
		" at range, causing " << this->_ranged_attack_damage << 
		" points of damage!\n";
}

void		FragTrap::meleeAttack(std::string const & target) const {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target <<
		" at close range, causing " << this->_melee_attack_damage << 
		" points of damage!\n";
}

void 		FragTrap::display() const {
	std::cout << "\nFR4G-TP\n" << "Name: " << this->_name << "\n" <<
		"Hit Points: " << this->_hit_points << "\n" <<
		"Max Hit Points: " << this->_max_hit_points << "\n" <<
		"Energy Points: " << this->_energy_points << "\n" <<
		"Max Energy Points: " << this->_max_energy_points << "\n" <<
		"Level: " << this->_level << "\n" <<
		"Melee Attack Damage: " << this->_melee_attack_damage << "\n" <<
		"Ranged Attack Damage: " << this->_ranged_attack_damage << "\n" <<
		"Armor Damage Reduction: " << this->_armor_damage_reduction	<< "\n\n";
}
