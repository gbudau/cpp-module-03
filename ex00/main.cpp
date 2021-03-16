#include <ctime>
#include <cstdlib>
#include "FragTrap.hpp"

int	main() {
	FragTrap	bar_bot("B4R-BOT");
	FragTrap	rambo("R4MB0");
	FragTrap	custom_tp(bar_bot);

	srand(time(NULL));
	bar_bot.displayStats();
	custom_tp.displayStats();
	custom_tp = rambo;
	custom_tp.displayStats();

	bar_bot.rangedAttack("Brick");
	bar_bot.meleeAttack("Mordecai");
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
	bar_bot.beRepaired(120);
	bar_bot.displayStats();
	bar_bot.vaulthunter_dot_exe("Roland");
	std::cout << "\n";
	bar_bot.vaulthunter_dot_exe("Lilith");
	std::cout << "\n";
	bar_bot.vaulthunter_dot_exe("Zarpedon");
	std::cout << "\n";
	bar_bot.vaulthunter_dot_exe("Handsome Jack");
	std::cout << "\n";
	bar_bot.vaulthunter_dot_exe("Mordecai");
	std::cout << "\n";
	bar_bot.vaulthunter_dot_exe("Brick");
	std::cout << "\n";
}
