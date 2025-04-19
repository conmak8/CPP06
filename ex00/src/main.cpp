/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */\
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:26:36 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/19 02:12:18 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"


// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Error: Wrong number of arguments" << std::endl;
// 		std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
// 		return (1);
// 	}
	
// 	// ScalarConverter convert::convert(argv[1]);
// 	ScalarConverter::convert(argv[1]);
	
// 	return (0);
// }

static void waitForEnter()
{
	std::cout << GRAY_1 << "Press " << BOLD << "Enter" << GRAY_1 << " to move to next category..." << RESET << std::endl;
	std::cin.get(); 
}

static void run_tests()
{
	// CATEGORY 1️⃣ Basics
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "       CATEGORY 1️⃣ : BASIC INPUTS    " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;
	
	ScalarConverter::convert("a");
	ScalarConverter::convert("0");
	ScalarConverter::convert("-0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("z");
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 2️⃣ INT Limits
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "    CATEGORY 2️⃣ : INT LIMITS & OVERFLOWS " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert("2147483647"); // INT_MAX
	ScalarConverter::convert("-2147483648"); // INT_MIN
	ScalarConverter::convert("2147483648"); // Overflow
	ScalarConverter::convert("-2147483649"); // Underflow
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 3️⃣ Float Tests
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "      CATEGORY 3️⃣ : FLOAT INPUTS " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("-42.0f");
	ScalarConverter::convert("4.2f");
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("-0.0f");
	ScalarConverter::convert("1234567.0f");
	ScalarConverter::convert("1.17549e-38f"); // FLT_MIN
	ScalarConverter::convert("3.40282e+38f"); // FLT_MAX
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 4️⃣ Double Tests
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "      CATEGORY 4️⃣ : DOUBLE INPUTS " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert("42.0");
	ScalarConverter::convert("-42.0");
	ScalarConverter::convert("4.2");
	ScalarConverter::convert("-4.2");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("-0.0");
	ScalarConverter::convert("1.79769e+308"); // DBL_MAX
	ScalarConverter::convert("2.22507e-308"); // DBL_MIN
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 5️⃣ Pseudo literals
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << " CATEGORY 5️⃣ : PSEUDO-LITERALS TESTS " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 6️⃣ Extreme Big/Small numbers
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << " CATEGORY 6️⃣ : EXTREME VALUES " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert("9999999999999999999999999999999");
	ScalarConverter::convert("-9999999999999999999999999999999");
	ScalarConverter::convert("1e1000");
	ScalarConverter::convert("-1e1000");
	ScalarConverter::convert("1e-1000");
	ScalarConverter::convert("-1e-1000");
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 7️⃣ Invalid Inputs
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << " CATEGORY 7️⃣ : INVALID INPUTS " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert("hello world");
	ScalarConverter::convert("");
	ScalarConverter::convert("^35");
	ScalarConverter::convert("..34");
	ScalarConverter::convert("-+21");
	ScalarConverter::convert("42f"); // Incorrect float
	ScalarConverter::convert("f");
	ScalarConverter::convert(".");
	ScalarConverter::convert("1.2.3");
	std::cout << std::endl;
	waitForEnter();

	// CATEGORY 8️⃣ Weird Single Chars
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << " CATEGORY 8️⃣ : EDGE SINGLE CHARS " << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	ScalarConverter::convert(" ");
	ScalarConverter::convert("\n");
	ScalarConverter::convert("1");
	ScalarConverter::convert("!");
	std::cout << std::endl;
	waitForEnter();
}

int main(int argc, char **argv) {
	if (argc == 1)
		run_tests();
	else if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << RED << "Error: " << RESET << "Only one argument is accepted." << std::endl;
	return 0;
}
