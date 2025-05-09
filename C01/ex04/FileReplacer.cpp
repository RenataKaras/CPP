/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FileReplacer.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 14:49:05 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/08 15:57:04 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string input, std::string findStr, std::string replaceStr)
{
	_input = input;
	_output = input + ".replace";
	_s1 = findStr;
	_s2 = replaceStr;
	
	std::cout << "FileReplacer constructor called" << std::endl;
}

FileReplacer::~FileReplacer()
{
	std::cout << "FileReplacer deconstructor called" << std::endl;
}

bool	FileReplacer::_validateArgs()
{
	if (_input.empty() || _s1.empty())
	{
		std::cerr << "Please use ./replace <filename> <s1> <s2>" << std::endl;
		std::cerr << "<s1> cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

bool	FileReplacer::_openFiles(std::ifstream &inFile, std::ofstream &outFile)
{
	inFile.open(_input);
	if (!inFile.is_open())
	{
		std::cerr << "Cannot open input file" << std::endl;
		return (false);
	}
	
	outFile.open(_output);
	if (!outFile.is_open())
	{
		std::cerr << "Cannot open output file" << std::endl;
		return (false);
	}
	return (true);
}

void	FileReplacer::_process(std::ifstream &inFile, std::ofstream &outFile)
{
	std::string	line;
	size_t		pos;

	while (std::getline(inFile, line)) //reads inFile line by line and stores each line in 'line'
	{
		pos = 0;
		while (true)
		{
			pos = line.find(_s1, pos); //starting at index pos where the next occurence of substring _s1 is?
			if (pos == std::string::npos) //this is what 'find' returns if there's no _s1 after pos
				break ;
			
			std::string	partBefore = line.substr(0, pos);
			std::string	partAfter = line.substr(pos + _s1.length());
			
			line = partBefore + _s2 + partAfter;
			pos = pos + _s2.length();
		}
		outFile << line;
		if (!inFile.eof())
			outFile << '\n';
	}
}

void	FileReplacer::run()
{
	if (!_validateArgs())
		return ;

	/* ifstream and ofstream behave like cin and cout but read from or write to disk instead of console */
	std::ifstream	inFile; //an input file stream called inFile
	std::ofstream	outFile; //an output file stream called outFile
	
	if (!_openFiles(inFile, outFile))
		return ;
	
	_process(inFile, outFile);
	
	inFile.close();
	outFile.close();
}