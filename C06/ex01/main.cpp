/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/04 12:35:00 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 14:30:25 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data original;
	Data *restored;
	uintptr_t raw;

	original.value = 42;

	std::cout << "Original pointer: " << &original << std::endl;
	std::cout << "Original value: " << original.value << std::endl;
	
	raw = Serializer::serialize(&original);
	std::cout << "Serialized uintptr: " << raw << std::endl;

	// raw += 1;

	restored = Serializer::deserialize(raw);
	std::cout << "Restored pointer: " << restored << std::endl;
	std::cout << "Restored value: " << restored->value << std::endl;

	if (restored == &original)
		std::cout << "Success: pointer restored" << std::endl;
	else
		std::cout << "Failure: pointer mismatch" << std::endl;

	return 0;
}