/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:26:36 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/18 17:30:25 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
		return (1);
	}
	
	// ScalarConverter convert::convert(argv[1]);
	ScalarConverter::convert(argv[1]);
	
	return (0);
}
