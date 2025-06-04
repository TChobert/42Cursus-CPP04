/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:45:21 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/28 16:45:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << GREEN << "Cure: default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << GREEN << "Cure: copy constructor called" << RESET << std::endl;
}

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
		std::cout << GREEN << "Cure: assignement operator called" << RESET << std::endl;
	}
	return (*this);
}

Cure::~Cure(void) {
	std::cout << GREEN << "Cure: destructor called" << RESET << std::endl;
}

Cure*	Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
