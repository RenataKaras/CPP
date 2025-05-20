/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 14:49:58 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/20 13:54:55 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n— Constructing a ScavTrap named “Serena” —\n";
    ScavTrap s("Serena");

    std::cout << "\n— Testing ScavTrap special ability —\n";
    s.guardGate();

    std::cout << "\n— Testing overridden attack() —\n";
    s.attack("IntruderBot");

    std::cout << "\n— Testing takeDamage & beRepaired (inherited) —\n";
    s.takeDamage(30);
    s.beRepaired(20);

    std::cout << "\n— Testing copy & assignment —\n";
    ScavTrap copyS(s);      // copy ctor
    ScavTrap assignS;       
    assignS = s;            // assignment

    std::cout << "\n— Exiting main(), destructors will fire —\n";
    return 0;
}