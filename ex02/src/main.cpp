/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:44:30 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/22 02:22:48 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Identify.hpp"
// #include "Colors.hpp"
// #include <iostream>

// int main ()
// {
// 	Base* obj = generate();
	
// 	std::cout << "\nIdentify with pointer:" << std::endl;
// 	identify(obj);
	
// 	std::cout << "\nIdentify with reference:" << std::endl;
// 	identify(*obj);
	
// 	std::cout << "\nIdentify with invalid pointer:" << std::endl;
// 	Base* invalid = NULL;
// 	identify(invalid);
	
// 	delete obj;
// 	delete invalid;
// 	return (0);
// }

//=================================================================//
// * Main on steroids 

#include "Identify.hpp"
#include "Colors.hpp"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time

static void waitForEnter()
{
	std::cout << DARK_GREY << "Press " << BOLD << "Enter" << DARK_GREY << " to move to next test..." << RESET << std::endl;
	std::cin.get();
}

static void test_single_generate_and_identify()
{
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "      TEST 1️⃣ : Single Generation" << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	Base* obj = generate();
	std::cout << std::endl;

	std::cout << GREEN << "Identification by POINTER:" << RESET << std::endl;
	identify(obj);

	std::cout << GREEN << "\nIdentification by REFERENCE:" << RESET << std::endl;
	identify(*obj);
	delete obj;

	std::cout << std::endl;
	waitForEnter();
}

static void test_multiple_generations()
{
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "      TEST 2️⃣ : Multiple Generations" << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << YELLOW << "\n[ Round " << (i + 1) << " ]" << RESET << std::endl;
		Base* obj = generate();
		std::cout << std::endl;

		std::cout << GREEN << "Identification by POINTER:" << RESET << std::endl;
		identify(obj);

		std::cout << GREEN << "\nIdentification by REFERENCE:" << RESET << std::endl;
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}
	waitForEnter();
}

static void test_invalid_case()
{
	std::cout << CYAN << "\n-------------------------------------------" << RESET << std::endl;
	std::cout << CYAN << BOLD << "      TEST 3️⃣ : Invalid Case (Optional)" << RESET << std::endl;
	std::cout << CYAN << "-------------------------------------------" << RESET << std::endl;

	std::cout << YELLOW "\nIdentify with invalid pointer:" RESET << std::endl;
	
	Base* invalid = NULL;
	identify(invalid);
	
	delete invalid;

	waitForEnter();
}

int main(int argc, char **argv)
{
	(void)argv;

	srand(time(NULL)); // always random!

	if (argc == 1)
	{
		test_single_generate_and_identify();
		test_multiple_generations();
		test_invalid_case();
	}
	else
		std::cout << RED << "Error: " << RESET << "This test does not accept arguments." << std::endl;
		
	return (0);
}
