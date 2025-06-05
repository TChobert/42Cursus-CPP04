/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:38:57 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 14:39:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

class WrongAnimal {

	protected:

	std::string	_type;

	public:

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator=(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	void				setType(const std::string& type);
	const std::string&	getType(void) const;
	void				makeSound(void) const;
};

#endif
