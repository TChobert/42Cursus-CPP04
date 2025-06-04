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
	std::cout << YELLOW << "AMateria: default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << YELLOW << "AMateria: parametrized constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << YELLOW << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << YELLOW << "AMateria: assignation operator called" << RESET << std::endl;
	return (*this);
}

AMateria::~AMateria(void) {
	std::cout << YELLOW << "AMateria: destructor called" << RESET << std::endl;
}

///// MEMBERS FUNCTIONS /////

std::string const&	AMateria::getType(void) const {
	return (_type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}
