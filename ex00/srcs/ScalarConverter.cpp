/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:49:17 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/03 01:45:11 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>						// std::strtol std::strtof std::strtod
#include <cerrno>						// errno, ERANGE
#include <limits>						// std::numeric_limits
#include <string>						// std::string

ScalarConverter::ScalarConverter() {
	
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {

	return *this;
}

ScalarConverter::~ScalarConverter() {
	
}


bool	ScalarConverter::isCharLiteral(const std::string& literal) {
	
	return literal.size() == 1 && !std::isdigit(literal[0]);
}

bool	ScalarConverter::isIntLiteral(const std::string& literal) {
	
	errno = 0;
	char*	end = NULL;
	long	val = std::strtol(literal.c_str(), &end, 10);

	if (*end != '\0' || literal.empty() || errno == ERANGE)
		return false;
	
	return val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool	ScalarConverter::isFloatLiteral(const std::string& literal) {

	if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal.empty() || literal.back() != 'f')
		return false;
	
	errno = 0;
	char*	end = NULL;
	
	std::strtof(literal.c_str(), &end);

	return *end == 'f' && *(end + 1) == '\0' && errno != ERANGE;
}

bool	ScalarConverter::isDoubleLiteral(const std::string& literal) {

	if (literal == "inf" || literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if (literal.empty())
		return false;

	errno = 0;
	char*	end = NULL;

	std::strtod(literal.c_str(), &end);

	return *end == '\0' && errno != ERANGE;
}

void	ScalarConverter::convert(const std::string& literal) {
	
	
}