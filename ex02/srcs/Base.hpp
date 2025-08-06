/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:58:55 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/08/06 16:14:14 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
private:

public:
	virtual ~Base();

	static Base*	generate(void);
	static void		identify(Base* p);
	static void		identify(Base& p);
};

#endif
