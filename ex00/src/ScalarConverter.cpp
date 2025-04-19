/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:52 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/19 02:42:16 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp" //for the colors
#include <iomanip> //setprecision
#include <sstream> //istringstream
#include <limits> //numeric_limits 
#include <cmath> //isnan
#include <cstdlib> //atoi, atof


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
static bool isChar(const std::string &str)  // ? static and why?
{
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

static bool isInt(const std::string &str)
{
	std::istringstream iss(str);  // diki tou vivliothiki??
	int val;
	return ((iss >> val) && (iss.eof()));
}

static bool isFloat(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if (str.back() != 'f')
		return false;
	std::string numberPart = str.substr(0, str.length() - 1);
	std::istringstream iss(numberPart);
	float val;
	return ((iss >> val) && iss.eof());
}

static bool isDouble(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	std::istringstream iss(str);
	double val;
	return ((iss >> val) && (iss.eof()));
}

static void printConversions(double inputValue)
{
	// PRINTING CONVERSIONS
	std::cout << CYAN << "Conversions:" << RESET << std::endl;

	// CHAR
	std::cout << "char: ";
	if (std::isnan(inputValue) || inputValue < 0 || inputValue > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(inputValue)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(inputValue) << "'";
	std::cout << std::endl;

	// INT
	std::cout << "int: ";
	if (std::isnan(inputValue) || inputValue > std::numeric_limits<int>::max() || inputValue < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(inputValue);
	std::cout << std::endl;

	// FLOAT
	std::cout << "float: ";
	if (std::isnan(inputValue))
		std::cout << "nanf";
	else if (std::isinf(inputValue))
		std::cout << (inputValue> 0 ? "+inff" : "-inff");
	else
		std::cout << std::fixed << std::setprecision(1) <<  static_cast<float>(inputValue) << "f";
	std::cout << std::endl;

//===============================-==========================//

	// DOUBLE
	std::cout << "double: ";
	if (std::isnan(inputValue))
		std::cout << "nan";
	else if (std::isinf(inputValue))
		std::cout << (inputValue > 0 ? "+inf" : "-inf");
	else
		std::cout << std::fixed << std::setprecision(1) << inputValue;
	std::cout << std::endl;
}


void ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
	{
		char c = literal[0];
		std::cout << "[Detected type: char]" << RED " -> " RESET << literal << std::endl;
		printConversions(static_cast<double>(c));
		std::cout << std::endl;
	}
	else if (isInt(literal))
	{
		int i = std::atoi(literal.c_str());
		std::cout << "[Detected type: int]" << RED " -> " RESET << literal << std::endl;
		printConversions(static_cast<double>(i));
		std::cout << std::endl;
	}
	else if (isFloat(literal))
	{
		float f = std::atof(literal.c_str());
		std::cout << "[Detected type: float]" << RED " -> " RESET << literal << std::endl;
		printConversions(static_cast<double>(f));
		std::cout << std::endl;
	}
	else if (isDouble(literal))
	{
		double d = std::atof(literal.c_str());
		std::cout << "[Detected type: double]" << RED " -> " RESET << literal << std::endl;
		printConversions(d);
		std::cout << std::endl;
	}
	else
		std::cout << "❌ Unknow literal" << RED " -> " RESET << literal << std::endl;
}
