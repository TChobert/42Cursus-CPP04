/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:01:19 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 14:01:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

///// CANONICAL /////

Dog::Dog(void) : Animal() {
	_type = "Dog";
	std::cout << BLUE << "Dog: default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->_type = other._type;
	std::cout << BLUE << "Dog: copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << BLUE << "Dog: assignement operator called" << RESET << std::endl;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << BLUE << "Dog: destructor called" << RESET << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	Dog::makeSound(void) const {
	std::cout << BLUE << "Bark" << RESET << std::endl;
}
