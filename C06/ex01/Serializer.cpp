/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/04 12:24:33 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 12:36:40 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}