/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 14:49:58 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/19 15:03:08 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    // 1) Test default constructor
    ClapTrap a;
    std::cout << "\n";

    // 2) Test parameterized constructor
    ClapTrap b("Blinky");
    std::cout << "\n";

    // 3) Test copy constructor
    ClapTrap c(b);
    std::cout << "\n";

    // 4) Test assignment operator
    ClapTrap d;
    d = b;
    std::cout << "\n";

    // 5) Test basic attack => energy should drop, damage printed
    b.attack("TargetDummy");
    b.attack("TargetDummy");
    std::cout << "\n";

    // 6) Drain energy to zero then try to attack again
    for (int i = 0; i < 10; ++i)
        b.attack("EmptyEnergyTest");
    std::cout << "\n";

    // 7) Test takeDamage
    c.takeDamage(3);
    c.takeDamage(10); // should floor at 0
    std::cout << "\n";

    // 8) Test beRepaired (on an alive and on a destroyed ClapTrap)
    a.beRepaired(5);
    a.takeDamage(15);
    a.beRepaired(5);  // should not repair, because HP=0
    std::cout << "\n";

    std::cout << "End of tests — destructors will now run as objects go out of scope\n";
    return 0;
}

// int	main(){
// 	{
// 		std::cout << "\nUsing up all energy\n\n";
// 		ClapTrap	a;

// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.attack("Chad");
// 		a.beRepaired(10);
// 	}
// 	{
// 		std::cout << "\nLosing all hp\n\n";
// 		ClapTrap	a;

// 		a.takeDamage(5);
// 		a.takeDamage(10);
// 		a.attack("Chad");
// 		a.beRepaired(10);
// 	}
// 	{
// 		std::cout << "\nTaking damage and repairing it\n\n";
// 		ClapTrap	a;

// 		a.takeDamage(5);
// 		a.beRepaired(1);
// 		a.beRepaired(1);
// 		a.beRepaired(1);
// 		a.beRepaired(5);
// 		a.takeDamage(20);
// 	}
// }