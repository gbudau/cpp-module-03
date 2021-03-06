#include "ScavTrap.hpp"

static const std::string	scavtrap_challenges[] = {
	"You Spin Me Right Round",
	"Scratch An Eldritch",
	"Qu'est-Ce Que C'est",
	"Show Me What You Got.",
	"You Pass Butter",
	"Get Outta The Way!",
	"Avada kedavra!",
	"Go On Without Me!",
	"Hack The Planet!",
};

ScavTrap::ScavTrap(std::string const & name)
	: _name(name), _hit_points(100), _max_hit_points(100), _energy_points(50),
	_max_energy_points(50), _level(1), _melee_attack_damage(20),
	_ranged_attack_damage(15), _armor_damage_reduction(3) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	this->_print_quote("Here I come to save the day!");
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	this->_print_quote("My servos... are seizing... Robot down!");
	return;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
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
	this->_print_quote("Recompiling my combat code!");
	return *this;
}

void		ScavTrap::rangedAttack(std::string const & target) const {
	this->_print_quote("Get off my lawn!");
	std::cout << "SC4V-TP " << this->_name <<
		" attacks " << target <<
		" at range, causing " << this->_ranged_attack_damage <<
		" points of damage!\n";
}

void		ScavTrap::meleeAttack(std::string const & target) const {
	this->_print_quote("This is why you do your homework!");
	std::cout << "SC4V-TP " << this->_name <<
		" attacks " << target <<
		" at close range, causing " << this->_melee_attack_damage <<
		" points of damage!\n";
}

void		ScavTrap::takeDamage(unsigned int amount) {
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

void		ScavTrap::beRepaired(unsigned int amount) {
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
		this->_print_quote("Good as new, I think. Am I leaking?");
	}
	this->_print_info();
}

void		ScavTrap::challengeNewcomer(std::string const & target) {
	int random_challenge = rand() %
		(sizeof(scavtrap_challenges) / sizeof(scavtrap_challenges[0]));
	std::cout << "SC4V-TP " << this->_name << ": Hey, " << target <<
		". A new challenge is available. It's called \"" <<
		scavtrap_challenges[random_challenge] << "\"\n";
}

void		ScavTrap::_print_quote(std::string const & quote) const {
	std::cout << "SC4V-TP " <<  this->_name <<
		": \"" << quote << "\"\n";
}

void		ScavTrap::_print_info() const {
	std::cout << "SC4V-TP " << this->_name << " [LVL " <<
		this->_level << "] " <<
		this->_hit_points << "/" << this->_max_hit_points << "HP " <<
		this->_energy_points << "/" << this->_max_energy_points << "EP\n";
}
