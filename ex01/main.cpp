#include <ctime>
#include <cstdlib>
#include "ScavTrap.hpp"

int	main() {
	ScavTrap	vronica("VR-0N1CA");
	ScavTrap	scooter("SC00T3R");
	ScavTrap	custom_tp(vronica);

	srand(time(NULL));
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
