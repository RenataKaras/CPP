/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 12:23:48 by rkaras        #+#    #+#                 */
/*   Updated: 2026/03/10 12:55:55 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else if (b < a)
		return b;
	else
		return b;
}

template <typename T>
T max(T a, T b)
{
	if (a < b)
		return b;
	else if (b < a)
		return a;
	else
		return b;
}

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

#endif /* !WHATEVER_H */