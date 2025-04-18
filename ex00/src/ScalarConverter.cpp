/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:52 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/18 17:04:27 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


//-------OCF----------//
ScalarConverter::ScalarConverter () {};

ScalarConverter::ScalarConverter (const ScalarConverter &src) {(void)src;};

ScalarConverter &ScalarConverter::operator= (const ScalarConverter &src)
{
	(void)src;
	return *this;
};

ScalarConverter::~ScalarConverter () {};

//====================//
bool isChar(const std::string &str)  // ? static and why?
{
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool isInt(const std::string &str)
{
	std::istringstream iss(str);  // diki tou vivliothiki??
	int val;
	return ((iss >> val) && (iss.eof()));
}

bool isFloat(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")  // ? Diki tour vivliothiki??
		return true;
	if (str.back() != 'f')
		return false;
	std::string numberPart = str.substr(0, str.length() - 1);
	std::istringstream iss(numberPart);
	float val;
	return ((iss >> val) && iss.eof());
}

bool isDouble(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	std::istringstream iss(str);
	double val;
	return ((iss >> val) && (iss.eof()));
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
	{
		char c = literal[0];
		std::cout << "[Detected type: char]" << std::endl;
		printConversions(static_cast<double>(c));
	}
	else if (isInt(literal))
	{
		int i = std::atoi(literal.c_str());
		std::cout << "[Detected type: int]" << std::endl;
		printConvsersions(static_cast<double>(c));
	}
	else if (isFloat(literal))
	{
		float f = std::atof(literal.c_str()); // ! what happens with ending f BEWARE
		std::cout << "[Detected type: float]" << std::endl;
		printConversions(static_cast<double>(f));
	}
	else if (isDouble(literal))
	{
		double d = std::atof(literal.c_str());
		\cout << "[Detected type: double]" << std::endl;
		printConversions(d);
	}
	else
		std::cout << "❌ Unknow literal" << std::endl;
}


