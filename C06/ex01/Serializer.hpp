/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/03 16:41:01 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 14:26:24 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <cstdint>

struct Data {
	int value;
};

class Serializer
{
	public:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;
		~Serializer() = delete;

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

//uintptr -> unsigned integer type guaranteed to hold a pointer, large enough to store any pointer value

/*
reinterpret cast - performs bitwise reinterpreting of a value
	- reinterprets bits without modifying them
	- the ONLY cast in CPP allowed to convert between unrelated pointed types,
		or between pointer types and integer types


- exercise is a simplified example of serialization that shows that we can transform
	pointer -> integer -> pointer with no loss of information
*/
#endif /* !SERIALIZER_H */