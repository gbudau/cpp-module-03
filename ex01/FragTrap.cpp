#include "FragTrap.hpp"

enum	e_valut_hunter_attacks {
	VH_Attack_Name = 0,
	VH_Attack_Action = 1,
	VH_Attack_Quote = 2
};

static const std::string	vault_hunter_attacks[][3] = {
	{"One Shot Wonder",
	" pulls the trigger and unloads all ammo left in the magazine at once",
	"A whole lotta bullets in just one trigger pull!"},
	{"Pirate Ship Mode",
	" put's on his pirate hat, takes out four cannons and starts shooting",
	"Time to get swabby!"},
	{"Torgue Fiesta",
	" rapidly throws out grenades",
	"It's time for my free grenade giveaway!"},
	{"Miniontrap",
	" throws out a Turrettrap that shoots explosive rockets",
	"I'm going commando!"},
	{"Laser Inferno",
	" throws a disco ball, constantly shooting lasers",
	"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!"}
};

static const std::string	vault_hunter_quotes[] = {
	"I have an IDEA!",
	"This time it'll be awesome, I promise!",
	"It's happening... it's happening!",
	"What will he do next?",
	"It's like a box of chocolates..."
};

FragTrap::FragTrap(std::string const & name)
	: _name(name), _hit_points(100), _max_hit_points(100), _energy_points(100),
	_max_energy_points(100), _level(1), _melee_attack_damage(30),
	_ranged_attack_damage(20), _armor_damage_reduction(5) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	this->_print_quote("Let's get this party started!");
	return;
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
}

FragTrap::~FragTrap() {
	this->_print_quote("Ooh yeah, watch me! Watch me go!");
	return;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {
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
	this->_print_quote("Look out everybody!"
			"Things are about to get awesome!");
	return *this;
}

void		FragTrap::rangedAttack(std::string const & target) const {
	this->_print_quote("Take two bullets, then call me in the morning.");
	std::cout << "FR4G-TP " << this->_name <<
		" attacks " << target <<
		" at range, causing " << this->_ranged_attack_damage <<
		" points of damage!\n";
}

void		FragTrap::meleeAttack(std::string const & target) const {
	this->_print_quote("Ready for the PUNCHline?!");
	std::cout << "FR4G-TP " << this->_name <<
		" attacks " << target <<
		" at close range, causing " << this->_melee_attack_damage <<
		" points of damage!\n";
}

void		FragTrap::takeDamage(unsigned int amount) {
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

void		FragTrap::beRepaired(unsigned int amount) {
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

void		FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->_energy_points < 25) {
		this->_print_quote("Rrrrrgh...this isn't working!"
			   " I'm out of energy");
	} else {
		int random_attack = rand() %
			(sizeof(vault_hunter_attacks) / sizeof(vault_hunter_attacks[0]));
		std::cout << "FR4G-TP " << this->_name <<
			" vaulthunter.exe -> analyzing ...\n";
		int random_quote = rand() %
			(sizeof(vault_hunter_quotes) / sizeof(vault_hunter_quotes[0]));
		this->_print_quote(vault_hunter_quotes[random_quote]);
		std::cout << "FR4G-TP " << this->_name <<
			" vaulthunter.exe -> activating " <<
			vault_hunter_attacks[random_attack][VH_Attack_Name] << "\n";
		this->_print_quote(
				vault_hunter_attacks[random_attack][VH_Attack_Quote]);
		std::cout << "FR4G-TP " << this->_name <<
			vault_hunter_attacks[random_attack][VH_Attack_Action] <<
			" at " << target << "\n";
		this->_energy_points -= 25;
	}
	this->_print_info();
}

void	FragTrap::_print_quote(std::string const & quote) const {
	std::cout << "FR4G-TP " <<  this->_name <<
		": \"" << quote << "\"\n";
}

void	FragTrap::_print_info() const {
	std::cout << "FR4G-TP " << this->_name << " [LVL " <<
		this->_level << "] " <<
		this->_hit_points << "/" << this->_max_hit_points << "HP " <<
		this->_energy_points << "/" << this->_max_energy_points << "EP\n";
}
