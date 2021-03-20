#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const & name)
	: ClapTrap(name), FragTrap(name), NinjaTrap(name) {
		this->setType("SUP3R-TP");
		this->setHitPoints(FragTrap::getDefaultHitPoints());
		this->setMaxHitPoints(FragTrap::getDefaultMaxHitPoints());
		this->setEnergyPoints(NinjaTrap::getDefaultEnergyPoints());
		this->setMaxEnergyPoints(NinjaTrap::getDefaultMaxEnergyPoints());
		this->setLevel(1);
		this->setMeleeAttackDamage(NinjaTrap::getDefaultMeleeAttackDamage());
		this->setRangedAttackDamage(FragTrap::getDefaultRangedAttackDamage());
		this->setArmorDamageReduction(
									FragTrap::getDefaultArmorDamageReduction());
		this->_print_quote("Loading combat packages!");
		return;
}

SuperTrap::SuperTrap(SuperTrap const & src)
	: ClapTrap(src), FragTrap(src), NinjaTrap(src) {
		*this = src;
}

SuperTrap::~SuperTrap() {
	this->_print_quote("Good thing I don't have a soul!");
	return;
}

SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs) {
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
	this->_print_quote("Resequencing combat protocols!");
	return *this;
}

void		SuperTrap::rangedAttack(std::string const & target) const {
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const & target) const {
	NinjaTrap::rangedAttack(target);
}
