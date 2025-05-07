/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FileReplacer.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 14:36:13 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 15:49:51 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <iostream>
#include <fstream>

class	FileReplacer
{
	private:
		std::string	_input;
		std::string	_output;
		std::string	_s1;
		std::string	_s2;
	
		bool	_validateArgs();
		bool	_openFiles(std::ifstream &inFile, std::ofstream &outFile);
		void	_process(std::ifstream &inFile, std::ofstream &outFile);
	
	public:
		FileReplacer(std::string input, std::string findStr, std::string replaceStr);
		~FileReplacer();

		void	run();
};

#endif