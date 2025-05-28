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
	_brain = new Brain;
	std::cout << BLUE << "Cat: default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	this->_type = other._type;
	std::cout << BLUE << "Cat: copy constructor called" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain != NULL) {
			delete this->_brain;
		}
		this->_brain = new Brain(*other._brain);
		std::cout << BLUE << "Cat: affectation operator called" << RESET << std::endl;
	}
	return (*this);
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << BLUE << "Cat: destructor called" << RESET << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	Cat::makeSound(void) const {
	std::cout << BLUE << "Meow" << RESET << std::endl;
}

void	Cat::displayBrainLoc(void) {
	_brain->displayIdeasFirstAddress();
}
