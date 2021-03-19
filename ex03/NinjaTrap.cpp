#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const & name) : ClapTrap(name) {
	this->setType("FR4G-TP");
	this->setHitPoints(60);
	this->setMaxHitPoints(60);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDamage(60);
	this->setRangedAttackDamage(5);
	this->setArmorDamageReduction(0);
	this->_print_quote("I'm a robot ninja...");
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src) {
	*this = src;
}

NinjaTrap::~NinjaTrap() {
	this->_print_quote("You'll never see me going!");
	return;
}

NinjaTrap &	NinjaTrap::operator=(NinjaTrap const & rhs) {
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
	this->_print_quote("I'm invisible!");
	return *this;
}

void		NinjaTrap::rangedAttack(std::string const & target) const {
	this->_print_quote("Shoryuken!");
	std::cout << this->getType() << " " << this->getName() <<
		" attacks " << target <<
		" at range, causing " << this->getRangedAttackDamage() <<
		" points of damage!\n";
}

void		NinjaTrap::meleeAttack(std::string const & target) const {
	this->_print_quote("Punch punch! Fight!");
	std::cout << this->getType() << " " << this->getName() <<
		" attacks " << target <<
		" at close range, causing " << this->getMeleeAttackDamage() <<
		" points of damage!\n";
}

void		NinjaTrap::ninjaShoebox(ClapTrap const & claptrap) {
	std::cout << this->getType() << " " << this->getName() <<
		": Tell me your favorite joke, " << claptrap.getType() << "\n";
	std::cout << claptrap.getType() << " " << claptrap.getName() <<
		": Why can't T-Rex clap their hands?\n" <<
		claptrap.getType() << " " << claptrap.getName() <<
		": Because their extinct\n";
}

void		NinjaTrap::ninjaShoebox(FragTrap const & fragtrap) {
	std::cout << this->getType() << " " << this->getName() <<
		": Tell me your favorite joke, " << fragtrap.getType() << "\n";
	std::cout << fragtrap.getType() << " " << fragtrap.getName() <<
		": What do a big bar of chocolate and a frag grenade have in common?\n" <<
		fragtrap.getType() << " " << fragtrap.getName() <<
		": Everybody gets a piece\n";
}

void		NinjaTrap::ninjaShoebox(ScavTrap const & scavtrap) {
	std::cout << this->getType() << " " << this->getName() <<
		": Tell me your favorite joke, " << scavtrap.getType() << "\n";
	std::cout << scavtrap.getType() << " " << scavtrap.getName() <<
		": What do you call a group of superhero ScavTraps?\n" <<
		scavtrap.getType() << " " << scavtrap.getName() <<
		": The Scavengers\n";
}

void		NinjaTrap::ninjaShoebox(NinjaTrap const & ninjatrap) {
	std::cout << this->getType() << " " << this->getName() <<
		": Tell me your favorite joke, " << ninjatrap.getType() << "\n";
	std::cout << ninjatrap.getType() << " " << ninjatrap.getName() <<
		": What kind of shoes does ninja wear?\n" <<
		ninjatrap.getType() << " " << ninjatrap.getName() <<
		": Sneakers!\n";
}
