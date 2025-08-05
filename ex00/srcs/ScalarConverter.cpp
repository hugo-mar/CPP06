/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:49:17 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/05 01:00:38 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>						// std::strtol std::strtof std::strtod
#include <cerrno>						// errno, ERANGE
#include <limits>						// std::numeric_limits
#include <string>						// std::string
#include <iostream>						// std::cout
#include <cmath>						// std::isnan, std::isinf

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
	char* end = NULL;
	long val = std::strtol(literal.c_str(), &end, 10);

	if (*end != '\0' || literal.empty() || errno == ERANGE)
		return false;
	
	return val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool	ScalarConverter::isFloatLiteral(const std::string& literal) {

	if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal.empty() || literal[literal.size() - 1] != 'f')
		return false;
	
	errno = 0;
	char* end = NULL;
	
	std::strtof(literal.c_str(), &end);

	return *end == 'f' && *(end + 1) == '\0' && errno != ERANGE;
}

bool	ScalarConverter::isDoubleLiteral(const std::string& literal) {

	if (literal == "inf" || literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if (literal.empty())
		return false;

	errno = 0;
	char* end = NULL;

	std::strtod(literal.c_str(), &end);

	return *end == '\0' && errno != ERANGE;
}

static void	printCharConversion(char c) {
	
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	printIntConversion(int n) {
	
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(n))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

static float	getFloatFromString(const std::string& literal) {

	float f;
	
	if (literal == "inff" || literal == "+inff")
		f = std::numeric_limits<float>::infinity();
	else if (literal == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else if (literal == "nanf")
		f = std::numeric_limits<float>::quiet_NaN();
	else
		f = strtof(literal.c_str(), NULL);
	
	return f;
}

static void	printFloatConversion(float f) {
	
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(f)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	
	if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	if (!(f - static_cast<int>(f))) {
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	} else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

static double getDoubleFromString(const std::string& literal) {
	
	double d;
	
	if (literal == "inf" || literal == "+inf")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else if (literal == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else
		d = strtod(literal.c_str(), NULL);

	return d;
}

static void	printDoubleConversion(double d) {
	
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(d)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	if (!(d - static_cast<int>(d))) {
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

static void	printImpossible() {

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string& literal) {
	
	if (isCharLiteral(literal))
		return printCharConversion(literal[0]);
	if (isIntLiteral(literal)) 
		return printIntConversion(std::atoi(literal.c_str()));
	if (isFloatLiteral(literal))
		return printFloatConversion(getFloatFromString(literal));
	if (isDoubleLiteral(literal))
		return printDoubleConversion(getDoubleFromString(literal));
	printImpossible();
}
