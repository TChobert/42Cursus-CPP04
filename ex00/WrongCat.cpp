/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:01:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 15:01:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) :WrongAnimal() {
	_type = "WrongCat";
	std::cout << RED << "WrongCat: default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	this->_type = other._type;
	std::cout << RED << "WrongCat: copy constructor called" << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		this->_type = other._type;
	}
	std::cout << RED << "WrongCat: assignement operator called" << RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << RED << "WrongCat: destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << RED << "Mooooooo" << RESET << std::endl;
}
