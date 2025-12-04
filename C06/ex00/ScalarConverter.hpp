/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 16:01:28 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 12:21:28 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

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