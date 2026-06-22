/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 16:01:28 by rkaras        #+#    #+#                 */
/*   Updated: 2026/01/08 14:00:30 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath> //for isnan & isinf
#include <iomanip> //for std::fixed and std::setprecision

enum Type {
	CHAR,
	INT,
	FLOAT,
	FLOAT_PSEUDO,
	DOUBLE,
	DOUBLE_PSEUDO,
};

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		
		
		/*
		- when a member function of a class is declared static, it means that the function
		belongs to the CLASS itself, and NOT to any specific instance of the class.
		- cannot access *THIS, and has no access to instance members
		*/
		static void convert(const std::string &literal);
};

#endif

/*
static cast - because I'm converting known and related types, and I accept the possible data loss
	- it's compile-time conversion
*/