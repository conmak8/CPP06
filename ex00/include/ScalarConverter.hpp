/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:45:19 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/18 17:12:53 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>


class ScalarConverter
{
private:
		//-----------OCF-----------------//
		ScalarConverter();										// * Constructor (default, deleted)
		ScalarConverter(const ScalarConverter &src);			// * Copy constructor (deleted)
		ScalarConverter &operator=(const ScalarConverter &src); // * Assignment operator
		~ScalarConverter();										// * Destructor
		//============Methods===========//
public:
		static void convert(const std::string &literal);
};

#endif // !SCALARCONVERTER_HPP
