#include "FragTrap.hpp"

int	main() {
	FragTrap	bar_bot("B4R-BOT");
	FragTrap	rambo("R4MB0-TP");
	FragTrap	custom_tp(bar_bot);


	bar_bot.displayStats();
	custom_tp.displayStats();
	custom_tp = rambo;
	custom_tp.displayStats();

	bar_bot.rangedAttack("Brick");
	bar_bot.meleeAttack("Brick");
	bar_bot.takeDamage(5);
	bar_bot.takeDamage(50);
	bar_bot.takeDamage(50);
	bar_bot.takeDamage(10);
	bar_bot.takeDamage(10);
	bar_bot.takeDamage(10);
	bar_bot.displayStats();
	bar_bot.beRepaired(0);
	bar_bot.beRepaired(50);
	bar_bot.displayStats();
	bar_bot.beRepaired(70);
	bar_bot.displayStats();
}
