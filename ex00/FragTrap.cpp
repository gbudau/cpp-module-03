#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name)
	: _name(name), _hit_points(100), _max_hit_points(100), _energy_points(100),
	_max_energy_points(100), _level(1), _melee_attack_damage(30),
	_ranged_attack_damage(20), _armor_damage_reduction(5) {
	std::cout << "FR4G-TP " <<  this->_name <<
		": Let's get this party started!\n";
	return;
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
	std::cout << "FR4G-TP " << this->_name <<
		": Take two bullets, then call me in the morning.\n";
	std::cout << "FR4G-TP " << this->_name << " attacks " << target <<
		" at range, causing " << this->_ranged_attack_damage <<
		" points of damage!\n";
}

void		FragTrap::meleeAttack(std::string const & target) const {
	std::cout << "FR4G-TP " << this->_name <<
		": Ready for the PUNCHline?!\n";
	std::cout << "FR4G-TP " << this->_name << " attacks " << target <<
		" at close range, causing " << this->_melee_attack_damage <<
		" points of damage!\n";
}

void		FragTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points == 0) {
		std::cout << "FR4G-TP " << this->_name <<
			": I'M DEAD I'M DEAD OHMYGOD I'M DEAD!\n";
		std::cout << "FR4G-TP " << this->_name << " took 0 points of damage!\n";
	} else if (amount <= this->_armor_damage_reduction) {
		std::cout << "FR4G-TP " << this->_name << ": Can't touch this!\n";
		std::cout << "FR4G-TP " << this->_name << " took 0 points of damage!\n";
	} else {
		unsigned int damage_taken = amount - this->_armor_damage_reduction;
		if (this->_hit_points <= damage_taken) {
			damage_taken = this->_hit_points;
		}
		if (this->_hit_points == 0) {
			std::cout << "FR4G-TP " << this->_name <<
				": Oh my God, I'm leaking! I think I'm leaking!"
				" Ahhhh, I'm leaking! There's oil everywhere!\n";
		} else {
			std::cout << "FR4G-TP " << this->_name <<
				": Ow hohoho, that hurts! Yipes!\n";
		}
		this->_hit_points -= damage_taken;
		std::cout << "FR4G-TP " << this->_name << " took " << damage_taken <<
			" points of damage!\n";
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
		amount << " hit points\n";
	if (amount != 0) {
	std::cout << "FR4G-TP " << this->_name <<
		": Good as new, I think. Am I leaking?\n";
	}
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target) {
	enum	e_attacks	{Attack_Name = 0, Attack_Action = 1, Attack_Quote = 2};
	static const std::string	attacks[5][3] = {
		{"One Shot Wonder",
		" pulls the trigger and unloads all ammo left in the magazine at once",
		": A whole lotta bullets in just one trigger pull!\n"},
		{"Pirate Ship Mode",
		" put's on his pirate hat, takes out four cannons and starts shooting",
		": Time to get swabby!\n"},
		{"Torgue Fiesta",
		" rapidly throws out grenades",
		": It's time for my free grenade giveaway!\n"},
		{"Miniontrap",
		" throws out a Turrettrap that shoots explosive rockets",
		": I'm going commando!\n"},
		{"Laser Inferno",
		" throws a disco ball, constantly shooting lasers",
		": Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!\n"}
	};
	static const std::string	quotes[] = {
		": I have an IDEA!\n",
		": This time it'll be awesome, I promise!\n",
		": It's happening... it's happening!\n",
		": What will he do next?\n",
		": It's like a box of chocolates...\n"
	};

	if (this->_energy_points < 25) {
		std::cout << "FR4G-TP " << this->_name <<
			": Rrrrrgh...this isn't working!\n";
		std::cout << "FR4G-TP " << this->_name << " is out of energy\n";
	} else {
		int random_attack = rand() % (sizeof(attacks) / sizeof(attacks[0]));
		std::cout << "FR4G-TP " << this->_name <<
			" vaulthunter.exe -> analyzing ...\n";
		int random_quote = rand() % (sizeof(quotes) / sizeof(quotes[0]));
		std::cout << "FR4G-TP " << this->_name <<
			quotes[random_quote];
		std::cout << "FR4G-TP " << this->_name <<
			" vaulthunter.exe -> activating " <<
			attacks[random_attack][Attack_Name] << "\n";
		std::cout << "FR4G-TP " << this->_name <<
			attacks[random_attack][Attack_Quote];
		std::cout << "FR4G-TP " << this->_name <<
			attacks[random_attack][Attack_Action] << " at " << target << "\n";
		this->_energy_points -= 25;
		std::cout << "FR4G-TP " << this->_name << " " <<
			this->_energy_points << " energy points left\n";
	}
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
