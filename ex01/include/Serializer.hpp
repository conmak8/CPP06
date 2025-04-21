/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:45:36 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/19 14:15:52 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint> // for uintptr_t
# include "Data.hpp"


class Serializer
{
private:
		//----------OCF----------//
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();
public:
		// ----------Methods----------//
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif //!SERIALIZER_HPP
