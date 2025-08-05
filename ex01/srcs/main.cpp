/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:48:04 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/05 17:54:54 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {

	Data original;
	original.name = "Hugo";
	original.age = 45;
	original.hobby = "Coding";

	uintptr_t raw = Serializer::serialize(&original);

	Data* result = Serializer::deserialize(raw);

	if (result == &original)
		std::cout << "Pointers match: serialization and deserialization successful!" << std::endl;
	else
		std::cout << "Error: pointers do not match!" << std::endl;

	std::cout << "Name:  " << result->name  << std::endl;
	std::cout << "Age: " << result->age   << std::endl;
	std::cout << "Hobby: " << result->hobby << std::endl;

	return 0;
}
