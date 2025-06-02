/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:25:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/28 16:26:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	//std::cout << "Ice: default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	//std::cout << "Ice: copy constructor called" << std::endl;
}

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
		//std::cout << "Ice: affectation operator called" << std::endl;
	}
	return (*this);
}

Ice::~Ice(void) {
	std::cout << "Ice: destructor called" << std::endl;
}

Ice*	Ice::clone(void) const {
	return (new Ice(*this));
}

// void	Ice::use(ICharacter& target) {
// }
