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
	//std::cout << "Cure: default constructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type) {
	//std::cout << "Cure: parametrized constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	this->_type = other._type;
	//std::cout << "Cure: copy constructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
		this->_type = other._type;
		//std::cout << "Cure: assignement operator called" << std::endl;
	}
	return (*this);
}

Cure::~Cure(void) {
	//std::cout << "Cure: destructor called" << std::endl;
}

Cure*	Cure::clone(void) const {
	return (new Cure(*this));
}

// void	Cure::use(ICharacter& target) {
// }
