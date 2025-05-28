/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:09:31 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 16:09:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	for (size_t i = 0; i < sizeof(_ideas) / sizeof(_ideas[0]); ++i) {
		_ideas[i] = "Some idea";
	}
	std::cout << RED << "Brain: default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	for (size_t i = 0; i < sizeof(_ideas) / sizeof (_ideas[0]); ++i) {
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << RED << "Brain: copy constructor called" << RESET << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (size_t i = 0; i < sizeof(_ideas) / sizeof(_ideas[0]); ++i) {
			this->_ideas[i] = other._ideas[i];
		}
		std::cout << RED << "Brain: assignement operator called" << RESET << std::endl;
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << RED << "Brain: destructor called" << RESET << std::endl;
}

///// GETTERS /////

size_t	Brain::getIdeasSize(void) const {
	size_t	size = 0;

	size = sizeof(_ideas) / sizeof(_ideas[0]);
	return (size);
}

std::string	Brain::getIdea(size_t index) const {
	return (_ideas[index]);
}

void	Brain::displayIdeasFirstAddress(void) const {
	std::cout << &_ideas[0] << std::endl;
}
