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
		": Look out everybody! Things are about to get awesome!\n";
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

void		FragTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points == 0) {
		std::cout << "FR4G-TP " << this->_name << " took 0 points of damage!\n";
		std::cout << "FR4G-TP " << this->_name <<
			": What Is Dead May Never Die\n";
	} else if (amount <= this->_armor_damage_reduction) {
		std::cout << "FR4G-TP " << this->_name << " took 0 points of damage!\n";
		std::cout << "FR4G-TP " << this->_name << ": Can't touch this!\n";
	} else {
		unsigned int damage_taken = amount - this->_armor_damage_reduction;
		if (this->_hit_points <= damage_taken)
			damage_taken = this->_hit_points;
		this->_hit_points -= damage_taken;
		std::cout << "FR4G-TP " << this->_name << " took " << damage_taken << 
			" points of damage!\n";
		if (this->_hit_points == 0) {
			std::cout << "FR4G-TP " << this->_name <<
				": Oh my God, I'm leaking! I think I'm leaking!"
				" Ahhhh, I'm leaking! There's oil everywhere!\n";
		}
	}
}

void		FragTrap::beRepaired(unsigned int amount) {
	if (amount + this->_hit_points > this->_max_hit_points) {
		amount = this->_max_hit_points - this->_hit_points;
		this->_hit_points = this->_max_hit_points;
	} else {
		this->_hit_points += amount;
	}
	std::cout << "FR4G-TP " << this->_name << " gained " <<
		amount << " of hit points\n";
	if (amount != 0) {
	std::cout << "FR4G-TP " << this->_name << ": Good as new, I think. Am I leaking?\n";
	}
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target) const {
	std::cout << target << "\n";
}

void 		FragTrap::displayStats() const {
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
