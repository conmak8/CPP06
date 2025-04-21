/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:44:30 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/21 22:06:54 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

int main ()
{
	Base* obj = generate();
	
	std::cout << "\nIdentify with pointer:" << std::endl;
	identify(obj);
	
	std::cout << "\nIdentify with reference:" << std::endl;
	identify(*obj);
	
	std::cout << "\nIdentify with invalid pointer:" << std::endl;
	Base* invalid = NULL;
	identify(invalid);
	
	delete obj;
	delete invalid;
	return (0);
}
