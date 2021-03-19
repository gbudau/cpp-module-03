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

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	this->setType("SC4V-TP");
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(50);
	this->setMaxEnergyPoints(50);
	this->setLevel(1);
	this->setMeleeAttackDamage(20);
	this->setRangedAttackDamage(15);
	this->setArmorDamageReduction(3);
	this->_print_quote("Here I come to save the day!");
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
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
	this->_print_quote("Recompiling my combat code!");
	return *this;
}

void		ScavTrap::rangedAttack(std::string const & target) const {
	this->_print_quote("Get off my lawn!");
	std::cout << this->getType() << " " << this->getName() <<
		" attacks " << target <<
		" at range, causing " << this->getRangedAttackDamage() <<
		" points of damage!\n";
}

void		ScavTrap::meleeAttack(std::string const & target) const {
	this->_print_quote("This is why you do your homework!");
	std::cout << this->getType() << " " << this->getName() <<
		" attacks " << target <<
		" at close range, causing " << this->getMeleeAttackDamage() <<
		" points of damage!\n";
}

void		ScavTrap::challengeNewcomer(std::string const & target) {
	int random_challenge = rand() %
		(sizeof(scavtrap_challenges) / sizeof(scavtrap_challenges[0]));
	std::cout << this->getType() << " " << this->getName() << ": Hey, " <<
		target << ". A new challenge is available. It's called \"" <<
		scavtrap_challenges[random_challenge] << "\"\n";
}
