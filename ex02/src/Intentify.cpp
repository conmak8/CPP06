/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intentify.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:35:05 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/21 21:56:35 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <exception>


Base* generate()
{
	srand(time(nullptr));
	int random = rand() % 3;
	Base* base = nullptr;

	if (random == 0)
	{
		base = new A();
		std::cout << "Created : A instance" << std::endl;
	}
	else if (random == 1)
	{
		base = new B();
		std::cout << "Created: B istance" << std::endl;
	}
	else
	{
		base = new C();
		std::cout << "Created: C instance" << std::endl;
	}

	return (base);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer type is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer type is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer type is: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference type is: A" << std::endl;
		return;
	}
	catch(std::bad_cast &e) {}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference type is: B" << std::endl;
		return;
	}
	catch(std::bad_cast &e) {}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference type is: C" << std::endl;
		return;
	}
	catch(std::bad_cast &e) {}

	std::cout << "Reference: Unknown type" << std::endl;
}