/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 16:30:10 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/03 16:33:03 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
	
	double	value;
	int		type;
	
	if (isChar(literal)) {
		value = static_cast<double>(literal[0]);
		type = CHAR;
	}
	else if (isInt(literal)) {
		type = INT;
		value = static_cast<double>(std::stoi(literal));
	}
	else if (isFloat(literal)) {
		type = FLOAT;
		value = static_cast<double>(std::stof(literal));
	}
	else if (isPseudoLiteralFloat(literal)) {
		type = FLOAT_PSEUDO;
		value = convertPseudoValue(literal, type);
	}
	else if (isPseudoLiteralDouble(literal)) {
		type = DOUBLE_PSEUDO;
		value = convertPseudoValue(literal, type);
	}
	else if (isDouble(literal)) {
		type = DOUBLE;
		value = std::stod(literal);
	}
	else {
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	
	printConverted(value, type);
}