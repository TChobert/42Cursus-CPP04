/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:15:11 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/26 17:15:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

///// CANONICAL /////

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->_type = other._type;
	std::cout << "Animal: copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
		std::cout << "Animal: affectation operator called" << std::endl;
	}
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Animal: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

// Getters

std::string	Animal::getType(void) const {
	return (_type);
}

// Setters

void	Animal::setType(const std::string& type) {
	_type = type;
}
