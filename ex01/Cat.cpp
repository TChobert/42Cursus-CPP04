/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:05:03 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/26 18:05:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

///// CANONICAL /////

Cat::Cat(void) : Animal() {
	_type = "Cat";
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->_type = other._type;
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Cat: affectation operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
