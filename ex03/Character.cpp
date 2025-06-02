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

///// CANONICAL /////

Character::Character(void) : _name("Default"), _unequipedMaterials(NULL),
								_unequipedMaterialsCount(0) {
	setInventory();
	//std::cout << "Character: default constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name), _unequipedMaterials(NULL),
													_unequipedMaterialsCount(0) {
	setInventory();
	//std::cout << "Character: parametrized constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name), _unequipedMaterialsCount(other._unequipedMaterialsCount) {
	copyInventory(other._inventory);
	copyUnequipedMaterials(other._unequipedMaterials);
	//std::cout << "Character: default constructor called" << std::endl;
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		deleteInventory();
		deleteUnequipedMaterials();
		copyInventory(other._inventory);
		this->_name = other._name;
		this->_unequipedMaterialsCount = other._unequipedMaterialsCount;
		copyUnequipedMaterials(other._unequipedMaterials);
	}
	return (*this);
}

Character::~Character(void) {
	for (size_t i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL) {
			delete (_inventory[i]);
		}
	}
	if (_unequipedMaterials != NULL) {
		for (size_t i = 0; i < _unequipedMaterialsCount; ++i) {
			delete (_unequipedMaterials[i]);
		}
		delete[] _unequipedMaterials;
	}
	std::cout << "Character: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	Character::setInventory(void) {
	for (size_t i = 0; i < INVENTORY_SIZE; ++i) {
		_inventory[i] = NULL;
	}
}

void	Character::deleteInventory(void) {
	for (size_t i = 0; i < INVENTORY_SIZE; ++i) {
		if (_inventory[i] != NULL) {
			delete (_inventory[i]);
			_inventory[i] = NULL;
		}
	}
}

void	Character::copyInventory(AMateria * const otherInventory[]) {
	for (size_t i = 0; i < INVENTORY_SIZE; ++i) {
		if (otherInventory[i] != NULL) {
			this->_inventory[i] = otherInventory[i]->clone();
		}
		else
			this->_inventory[i] = NULL;
	}
}

void	Character::copyUnequipedMaterials(AMateria * const otherDroppedMaterials[]) {
	if (_unequipedMaterialsCount == 0) {
		_unequipedMaterials = NULL;
	}
	else {
		_unequipedMaterials = new AMateria * [_unequipedMaterialsCount];
		for (size_t i = 0; i < _unequipedMaterialsCount; ++i) {
				_unequipedMaterials[i] = otherDroppedMaterials[i]->clone();
		}
	}
}

void	Character::deleteUnequipedMaterials(void) {
	if (_unequipedMaterialsCount == 0) {
		return ;
	}
	for (size_t i = 0; i < _unequipedMaterialsCount; ++i) {
		if (_unequipedMaterials[i] != NULL) {
			delete (_unequipedMaterials[i]);
		}
	}
	delete[] (_unequipedMaterials);
	_unequipedMaterials = NULL;
	_unequipedMaterialsCount = 0;
}
