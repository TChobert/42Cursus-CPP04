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
	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (size_t i = 0; i < sizeof(_ideas) / sizeof (_ideas[0]); ++i) {
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain: copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (size_t i = 0; i < sizeof(_ideas) / sizeof(_ideas[0]); ++i) {
			this->_ideas[i] = other._ideas[i];
		}
		std::cout << "Brain: assignement operator called" << std::endl;
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain: destructor called" << std::endl;
}
