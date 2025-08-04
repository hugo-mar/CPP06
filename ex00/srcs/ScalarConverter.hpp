/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:15:55 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/02 20:55:56 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	static bool	isCharLiteral(const std::string& literal);
    static bool	isIntLiteral(const std::string& literal);
    static bool	isFloatLiteral(const std::string& literal);
    static bool	isDoubleLiteral(const std::string& literal);
	
public:
	static void	convert(std::string const& literal);
};

#endif