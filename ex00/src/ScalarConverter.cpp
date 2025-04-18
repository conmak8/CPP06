/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:52 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/18 16:57:51 by cmakario         ###   ########.fr       */
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

void ScalarConverter::convert(const std::sting &literal)
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


