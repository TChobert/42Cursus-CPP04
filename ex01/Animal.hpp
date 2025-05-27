/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:05:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/26 17:05:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <cstdlib>
# include <iostream>
# include <string>

class	Animal {

	protected:

	std::string	_type;

	public:

	Animal(void);
	Animal(const Animal& other);
	Animal&	operator=(const Animal& other);
	virtual ~Animal(void);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
	void			setType(const std::string& type);
};

#endif
