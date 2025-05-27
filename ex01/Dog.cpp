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
	_brain = new Brain;
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->_type = other._type;
	if (this->_brain != nullptr) {
		delete this->_brain;
	}
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other._type;
		if (this->_brain != nullptr) {
			delete this->_brain;
		}
		this->_brain = new Brain(*other._brain);
		std::cout << "Dog: assignement operator called" << std::endl;
	}
	return (*this);
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	Dog::makeSound(void) const {
	std::cout << "Bark" << std::endl;
}
