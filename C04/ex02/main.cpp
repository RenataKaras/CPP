/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 13:34:46 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/27 14:39:45 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	{
		std::cout << "***********Test from the subject***********" << std::endl;
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		delete j;
		delete i;
		std::cout << "\n";
	}
	{
		std::cout << "***********Testing the array***********" << std::endl;
		AAnimal *array[10];
		
		for (int i = 0; i < 10; i++)
		{
			if (i <= 4)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}
		
		for (int i = 0; i < 10; i++)
			array[i]->makeSound();
		
		for (int i = 0; i < 10; i++)
			delete array[i];
		std::cout << "\n";
	}
	{
		std::cout << "***********Testing the deep copy***********" << std::endl;
		Dog original;
		original.getBrain()->setIdea(0, "Want a snack");

		Dog copyConstr(original);
		Dog copyAssign;
		copyAssign = original;

		std::cout	<< "original brain ptr: " << original.getBrain() << std::endl
					<< "copyConstr brain ptr: " << copyConstr.getBrain() << std::endl
					<< "copyAssign brain ptr: " << copyAssign.getBrain() << std::endl
					<< std::endl;
					
		copyConstr.getBrain()->setIdea(0, "Go for a walk");
		
		std::cout	<< "original idea: " << original.getBrain()->getIdea(0) << std::endl
					<< "copyConstr idea: " << copyConstr.getBrain()->getIdea(0) << std::endl
					<< std::endl;

	}
	{
		// std::cout << "***********Testing the WrongAnimals***********" << std::endl;
		// WrongAnimal	*array[10];
		// for (int i = 0; i < 10; ++i)
		// 		array[i] = new WrongCat();
		
		// for (int i = 0; i < 10; ++i)
		// 	array[i]->makeSound();

		// for (int i = 0; i < 10; ++i)
		// 	delete array[i];
	}
	{
		// std::cout << "***********Testing the Abstract Class***********" << std::endl;
		// AAnimal *b = new AAnimal();
	}
	return 0;
}