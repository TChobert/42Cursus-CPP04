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
	std::cout << YELLOW << "Cat: default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->_type = other._type;
	std::cout << YELLOW << "Cat: copy constructor called" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << YELLOW << "Cat: affectation operator called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << YELLOW << "Cat: destructor called" << RESET << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	Cat::makeSound(void) const {
	std::cout << YELLOW << "Meow" << RESET << std::endl;
}
