#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main() {
	std::cout << "\n########## FragTrap class tests ##########\n\n";
	{
		FragTrap	bar_bot("B4R-BOT");
		FragTrap	rambo("R4MB0");
		FragTrap	custom_tp(bar_bot);

		custom_tp = rambo;

		std::cout << "\n";
		bar_bot.rangedAttack("Brick");
		bar_bot.meleeAttack("Mordecai");
		std::cout << "\n";
		bar_bot.takeDamage(5);
		bar_bot.takeDamage(50);
		bar_bot.takeDamage(50);
		bar_bot.takeDamage(10);
		bar_bot.takeDamage(10);
		bar_bot.takeDamage(10);
		std::cout << "\n";
		bar_bot.beRepaired(0);
		bar_bot.beRepaired(50);
		bar_bot.beRepaired(70);
		bar_bot.beRepaired(120);
		std::cout << "\n";
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
		rambo.vaulthunter_dot_exe("Lilith");
		std::cout << "\n";
	}
	std::cout << "\n########## ScavTrap class tests ##########\n\n";
	{
		ScavTrap	vronica("VR-0N1CA");
		ScavTrap	scooter("SC00T3R");
		ScavTrap	custom_tp(vronica);

		custom_tp = scooter;

		std::cout << "\n";
		vronica.rangedAttack("Brick");
		vronica.meleeAttack("Mordecai");
		std::cout << "\n";
		vronica.takeDamage(5);
		vronica.takeDamage(50);
		vronica.takeDamage(50);
		vronica.takeDamage(10);
		vronica.takeDamage(10);
		vronica.takeDamage(10);
		std::cout << "\n";
		vronica.beRepaired(0);
		vronica.beRepaired(50);
		vronica.beRepaired(70);
		vronica.beRepaired(120);
		std::cout << "\n";
		vronica.challengeNewcomer("Athena");
		vronica.challengeNewcomer("General Knoxx");
		vronica.challengeNewcomer("Nisha");
		vronica.challengeNewcomer("Handsome Jack");
		vronica.challengeNewcomer("Wilhelm");
		vronica.challengeNewcomer("Sir Hammerlock");
		std::cout << "\n";
	}
	std::cout << "\n########## ClapTrap class tests ##########\n\n";
	{
		ClapTrap	fragtrap("FR4G-TP",
				"fragtrap", 100, 100, 100, 100, 1, 30, 20, 5);
		ClapTrap	scavtrap("SC4V-TP", "scavtrap", 100, 100, 50, 50, 1, 20, 15, 3);
		ClapTrap	shapeshift(fragtrap);


		fragtrap.takeDamage(123);
		fragtrap.beRepaired(20);
		scavtrap.takeDamage(123);
		scavtrap.beRepaired(20);
		shapeshift.takeDamage(123);
		shapeshift.beRepaired(20);
		shapeshift = scavtrap;
		shapeshift.takeDamage(123);
		shapeshift.beRepaired(20);
	}
}
