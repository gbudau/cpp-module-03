#include "FragTrap.hpp"

const unsigned int	FragTrap::_default_hit_points = 100;
const unsigned int	FragTrap::_default_max_hit_points = 100;
const unsigned int	FragTrap::_default_energy_points = 100;
const unsigned int	FragTrap::_default_max_energy_points = 100;
const unsigned int	FragTrap::_default_level = 1;
const unsigned int	FragTrap::_default_melee_attack_damage = 30;
const unsigned int	FragTrap::_default_ranged_attack_damage = 20;
const unsigned int	FragTrap::_default_armor_damage_reduction = 5;

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

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	this->setType("FR4G-TP");
	this->setHitPoints(this->getDefaultHitPoints());
	this->setMaxHitPoints(this->getDefaultMaxHitPoints());
	this->setEnergyPoints(this->getDefaultEnergyPoints());
	this->setMaxEnergyPoints(this->getDefaultMaxEnergyPoints());
	this->setLevel(this->getDefaultLevel());
	this->setMeleeAttackDamage(this->getDefaultMeleeAttackDamage());
	this->setRangedAttackDamage(this->getDefaultRangedAttackDamage());
	this->setArmorDamageReduction(this->getDefaultArmorDamageReduction());
	this->_print_quote("Let's get this party started!");
	return;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	*this = src;
}

FragTrap::~FragTrap() {
	this->setType("FR4G-TP");
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
		this->setType(rhs.getType());
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setMaxHitPoints(rhs.getMaxHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setMaxEnergyPoints(rhs.getMaxEnergyPoints());
		this->setLevel(rhs.getLevel());
		this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
		this->setRangedAttackDamage(rhs.getRangedAttackDamage());
		this->setArmorDamageReduction(rhs.getArmorDamageReduction());
	}
	this->_print_quote("Look out everybody!"
			"Things are about to get awesome!");
	return *this;
}

void		FragTrap::rangedAttack(std::string const & target) const {
	this->_print_quote("Take two bullets, then call me in the morning.");
	std::cout << this->getType() << " " << this->getName() <<
		" attacks " << target <<
		" at range, causing " << this->getRangedAttackDamage() <<
		" points of damage!\n";
}

void		FragTrap::meleeAttack(std::string const & target) const {
	this->_print_quote("Ready for the PUNCHline?!");
	std::cout << this->getType() << " " << this->getName() <<
		" attacks " << target <<
		" at close range, causing " << this->getMeleeAttackDamage() <<
		" points of damage!\n";
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->getEnergyPoints() < 25) {
		this->_print_quote("Rrrrrgh...this isn't working!"
			   " I'm out of energy");
	} else {
		int random_attack = rand() %
			(sizeof(vault_hunter_attacks) / sizeof(vault_hunter_attacks[0]));
		std::cout << "FR4G-TP " << this->getName() <<
			" vaulthunter.exe -> analyzing ...\n";
		int random_quote = rand() %
			(sizeof(vault_hunter_quotes) / sizeof(vault_hunter_quotes[0]));
		this->_print_quote(vault_hunter_quotes[random_quote]);
		std::cout << this->getType() << " " << this->getName() <<
			" vaulthunter.exe -> activating " <<
			vault_hunter_attacks[random_attack][VH_Attack_Name] << "\n";
		this->_print_quote(
				vault_hunter_attacks[random_attack][VH_Attack_Quote]);
		std::cout << this->getType() << " " << this->getName() <<
			vault_hunter_attacks[random_attack][VH_Attack_Action] <<
			" at " << target << "\n";
		this->setEnergyPoints(this->getEnergyPoints() - 25);
	}
	this->_print_info();
}

unsigned int	FragTrap::getDefaultHitPoints() const {
	return this->_default_hit_points;
}

unsigned int	FragTrap::getDefaultMaxHitPoints() const {
	return this->_default_max_hit_points;
}

unsigned int	FragTrap::getDefaultEnergyPoints() const {
	return this->_default_energy_points;
}

unsigned int	FragTrap::getDefaultMaxEnergyPoints() const {
	return this->_default_max_energy_points;
}

unsigned int	FragTrap::getDefaultLevel() const {
	return this->_default_level;
}

unsigned int	FragTrap::getDefaultMeleeAttackDamage() const {
	return this->_default_melee_attack_damage;
}

unsigned int	FragTrap::getDefaultRangedAttackDamage() const {
	return this->_default_ranged_attack_damage;
}

unsigned int	FragTrap::getDefaultArmorDamageReduction() const {
	return this->_default_armor_damage_reduction;
}
