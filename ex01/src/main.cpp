/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:58:09 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/19 14:14:17 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"
#include <iostream>


int main()
{
	Data data = {"Mak", 34};
	
	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << data.name << " Age: " << data.age << std::endl;
	std::cout << "Address of data: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data(uintprt_t): " << raw << std::endl;

	Data* recovered = Serializer::deserialize(raw);
	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "Name: " << recovered->name << "Age: " << recovered->age << std::endl;
	std::cout << "Address of recovered: " << recovered << std::endl;

	if (recovered == &data)
		std::cout << "✅ SUCCESS: Recovered pointer matches original!" << std::endl;
	else
		std::cout << "❌ FAILURE: Pointers do not match!" << std::endl;

	return(0);
}
