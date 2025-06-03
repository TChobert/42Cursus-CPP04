/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:05:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/28 15:06:36 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

///// CANONICAL /////

AMateria::AMateria(void) : _type("Default") {
	//std::cout << "AMateria: default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	//std::cout << "AMateria: parametrized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
		// std::cout << "AMateria: assignation operator called" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria(void) {
	std::cout << "AMateria: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

std::string const&	AMateria::getType(void) const {
	return (_type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}