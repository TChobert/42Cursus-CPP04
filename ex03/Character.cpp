/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:34:05 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/02 14:34:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Default") {

	for (size_t i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	//std::cout << "Character: default constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	for (size_t i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	//std::cout << "Character: parametrized constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (size_t i = 0; i < 4; ++i) {
		if (other._inventory[i] != NULL) {
			this->_inventory[i] = other._inventory[i]->clone();
		}
		else {
			this->_inventory[i] = NULL;
		}
	}
	//std::cout << "Character: default constructor called" << std::endl;
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		for (size_t i = 0; i < 4; ++i) {
			if (other._inventory[i] != NULL) {
				this->_inventory[i] = other._inventory[i]->clone();
			}
			else {
				this->_inventory[i] = NULL;
			}
			this->_name = other._name;
		}
	}
	return (*this);
}
