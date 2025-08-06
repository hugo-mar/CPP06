/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:10:30 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/06 17:13:46 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main() {
	
	Base *objs[10];

	for (int i = 0; i < 10; ++i) {
		objs[i] = Base::generate();
	}

	std::cout << "Identification by pointer:\n";
	for (int i = 0; i < 10; ++i) {
		std::cout << "Object " << i + 1 << ": ";
		Base::identify(objs[i]);
	}

	std::cout << "\nIdentification by reference:\n";
	for (int i = 0; i < 10; ++i) {
		std::cout << "Object " << i + 1 << ": ";
		Base::identify(*objs[i]);
	}

	for (int i = 0; i < 10; ++i) {
		delete objs[i];
	}
	
	return 0;
}