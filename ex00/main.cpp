#include "FragTrap.hpp"

int	main() {
	FragTrap	fragnum("fragnum");
	FragTrap	godzilla("godzilla");
	FragTrap	newgodzilla(godzilla);

	godzilla.display();
	godzilla = fragnum;
	fragnum.display();
	godzilla.display();
	newgodzilla.display();
}
