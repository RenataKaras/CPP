/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 13:09:13 by rkaras        #+#    #+#                 */
/*   Updated: 2026/03/10 16:09:14 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>

void iter(T *array, const size_t length, void (*f)(T &))
{
	if (f)
	{
		for (size_t i = 0; i < length; i++)
			f(array[i]);
	}
}

#endif /* !ITER_H */