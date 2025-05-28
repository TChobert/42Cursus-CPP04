/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:42:46 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 14:43:14 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

///// CANONICAL /////

WrongAnimal::WrongAnimal(void) : _type("Wrong animal") {
	std::cout << "WrongAnimal: default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	WrongAnimal::makeSound(void) const {
	std::cout << "I'm not a cow" << std::endl;
}

void	WrongAnimal::setType(const std::string& type) {
	_type = type;
}

const std::string&	WrongAnimal::getType(void) const {
	return (_type);
}
