#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int	main() {
	std::cout << "########## FragTrap class tests ##########\n\n";
	{
		FragTrap	bar_bot("B4R-BOT");
		FragTrap	rambo("R4MB0");
		FragTrap	custom_ft(bar_bot);

		custom_ft = rambo;

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

	std::cout << "\n\n########## ScavTrap class tests ##########\n\n";
	{
		ScavTrap	vronica("VR-0N1CA");
		ScavTrap	scooter("SC00T3R");
		ScavTrap	custom_st(vronica);

		custom_st = scooter;

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

	std::cout << "\n\n########## ClapTrap class tests ##########\n\n";
	{
		ClapTrap	fragtrap("FR4G-TP",
				"R4MB0", 100, 100, 100, 100, 1, 30, 20, 5);
		ClapTrap	scavtrap("SC4V-TP", "VR-0N1CA", 100, 100, 50, 50, 1, 20, 15, 3);
		ClapTrap	shapeshift(fragtrap);


		std::cout << "\n";
		fragtrap.takeDamage(123);
		std::cout << "\n";
		fragtrap.beRepaired(20);
		std::cout << "\n";
		scavtrap.takeDamage(123);
		std::cout << "\n";
		scavtrap.beRepaired(20);
		std::cout << "\n";
		shapeshift.takeDamage(123);
		std::cout << "\n";
		shapeshift.beRepaired(20);
		std::cout << "\n";
		shapeshift = scavtrap;
		std::cout << "\n";
		shapeshift.takeDamage(123);
		std::cout << "\n";
		shapeshift.beRepaired(20);
		std::cout << "\n";
	}
	std::cout << "\n\n########## NinjaTrap class tests ##########\n\n";
	{
		ClapTrap	custom("CL4P-TP",
				"CU5TM-TP", 100, 100, 100, 100, 100, 100, 100, 100);
		FragTrap	rambo("R4MB0");
		ScavTrap	vronica("VR-0N1CA");

		std::cout << "\n";
		NinjaTrap	knifesai("KN1F3S41");
		NinjaTrap	tonfachucks("T0NF4CHUCKS");
		NinjaTrap	custom_nt(knifesai);

		custom_nt = tonfachucks;

		std::cout << "\n";
		knifesai.rangedAttack("Brick");
		knifesai.meleeAttack("Mordecai");
		std::cout << "\n";
		knifesai.takeDamage(5);
		knifesai.takeDamage(50);
		knifesai.takeDamage(50);
		knifesai.takeDamage(10);
		knifesai.takeDamage(10);
		knifesai.takeDamage(10);
		std::cout << "\n";
		knifesai.beRepaired(0);
		knifesai.beRepaired(50);
		knifesai.beRepaired(70);
		knifesai.beRepaired(120);
		std::cout << "\n";
		knifesai.ninjaShoebox(tonfachucks);
		std::cout << "\n";
		knifesai.ninjaShoebox(custom);
		std::cout << "\n";
		knifesai.ninjaShoebox(rambo);
		std::cout << "\n";
		knifesai.ninjaShoebox(vronica);
		std::cout << "\n";
	}
}
