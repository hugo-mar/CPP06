/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:19:38 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/05 17:53:13 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer&) {

}

Serializer& Serializer::operator=(const Serializer&) {

	return *this;
}

Serializer::~Serializer() {

}

uintptr_t Serializer::serialize(Data* ptr) {
	
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	
	return reinterpret_cast<Data*>(raw);
}