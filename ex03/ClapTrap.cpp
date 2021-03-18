#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const & type,
		std::string const & name, unsigned int hit_points,
		unsigned int max_hit_points, unsigned int energy_points,
		unsigned int max_energy_points, unsigned int level,
		unsigned int melee_attack_damage, unsigned int ranged_attack_damage,
		unsigned int armor_damage_reduction)
	: _type(type), _name(name), _hit_points(hit_points),
	_max_hit_points(max_hit_points), _energy_points(energy_points),
	_max_energy_points(max_energy_points), _level(level),
	_melee_attack_damage(melee_attack_damage),
	_ranged_attack_damage(ranged_attack_damage),
	_armor_damage_reduction(armor_damage_reduction) {
	this->_print_quote("Booting sequence complete. Hello!"
			" C to the L to the 4 to the P to the WHAAT!");
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
}

ClapTrap::~ClapTrap() {
	this->_print_quote("Roses are red and/Violets are blue/Wait... "
			"how many syllables was that?"
			" ClapTrap OUT!");
	return;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
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
	this->_print_quote("I'm Trap, Claptrap. Double oh... Trap.");
	return *this;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points == 0) {
		this->_print_quote("I'M DEAD I'M DEAD OHMYGOD I'M DEAD!");
	} else if (amount <= this->_armor_damage_reduction) {
		this->_print_quote("Can't touch this!");
	} else {
		unsigned int damage_taken = amount - this->_armor_damage_reduction;
		if (this->_hit_points <= damage_taken) {
			damage_taken = this->_hit_points;
		}
		this->_hit_points -= damage_taken;
		if (this->_hit_points == 0) {
			this->_print_quote("Oh my God, I'm leaking! I think I'm leaking!"
					" Ahhhh, I'm leaking! There's oil everywhere!");
		} else {
			this->_print_quote("Ow hohoho, that hurts! Yipes!");
		}
	}
	this->_print_info();
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points == 0 && amount != 0) {
		this->_print_quote("O-KAY! Thanks for giving me a second chance, God."
				" I really appreciate it.");
	}
	if (amount + this->_hit_points > this->_max_hit_points) {
		amount = this->_max_hit_points - this->_hit_points;
		this->_hit_points = this->_max_hit_points;
	} else {
		this->_hit_points += amount;
	}
	if (this->_hit_points != 0) {
		this->_print_quote("Sweet life juice! Aw yeah!");
	}
	this->_print_info();
}

void	ClapTrap::_print_quote(std::string const & quote) const {
	std::cout << this->_type << " " <<  this->_name <<
		": \"" << quote << "\"\n";
}

void	ClapTrap::_print_info() const {
	std::cout << this->_type << " " << this->_name << " [LVL " <<
		this->_level << "] " <<
		this->_hit_points << "/" << this->_max_hit_points << "HP " <<
		this->_energy_points << "/" << this->_max_energy_points << "EP\n";
}

std::string const &	ClapTrap::getType() const {
	return this->_type;
}

std::string const &	ClapTrap::getName() const {
	return this->_name;
}

unsigned int		ClapTrap::getHitPoints() const {
	return this->_hit_points;
}

unsigned int		ClapTrap::getMaxHitPoints() const {
	return this->_max_hit_points;
}

unsigned int		ClapTrap::getEnergyPoints() const {
	return this->_energy_points;
}

unsigned int		ClapTrap::getMaxEnergyPoints() const {
	return this->_max_energy_points;
}

unsigned int		ClapTrap::getLevel() const {
	return this->_level;
}

unsigned int		ClapTrap::getMeleeAttackDamage() const {
	return this->_melee_attack_damage;
}

unsigned int		ClapTrap::getRangedAttackDamage() const {
	return this->_ranged_attack_damage;
}

unsigned int		ClapTrap::getArmorDamageReduction() const {
	return this->_armor_damage_reduction;
}

void				ClapTrap::setType(std::string const & type) {
	this->_type = type;
}

void				ClapTrap::setName(std::string const & name) {
	this->_name = name;
}

void				ClapTrap::setHitPoints(unsigned int hit_points) {
	this->_hit_points = hit_points;
}

void				ClapTrap::setMaxHitPoints(unsigned int max_hit_points) {
	this->_max_hit_points = max_hit_points;
}

void				ClapTrap::setEnergyPoints(unsigned int energy_points) {
	this->_energy_points = energy_points;
}

void				ClapTrap::setMaxEnergyPoints(
											unsigned int max_energy_points) {
	this->_max_energy_points = max_energy_points;
}

void				ClapTrap::setLevel(unsigned int level) {
	this->_level = level;
}

void				ClapTrap::setMeleeAttackDamage(
											unsigned int melee_attack_damage) {
	this->_melee_attack_damage = melee_attack_damage;
}

void				ClapTrap::setRangedAttackDamage(
											unsigned int ranged_attack_damage) {
	this->_ranged_attack_damage = ranged_attack_damage;
}

void				ClapTrap::setArmorDamageReduction(
										unsigned int armor_damage_reduction) {
	this->_armor_damage_reduction = armor_damage_reduction;
}
