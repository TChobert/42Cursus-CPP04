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
	deleteInventory();
	deleteUnequipedMaterials();
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

void	Character::saveUnequipedMaterial(int idx) {
	if (_unequipedMaterialsCount == 0) {
		_unequipedMaterials = new AMateria * [1];
		_unequipedMaterials[0] = _inventory[idx];
	}
	else {
		AMateria	**newStash = new AMateria * [_unequipedMaterialsCount + 1];
		for (size_t i = 0; i < _unequipedMaterialsCount; ++i) {
			newStash[i] = _unequipedMaterials[i];
		}
		newStash[_unequipedMaterialsCount] = _inventory[idx];
		delete[] _unequipedMaterials;
		_unequipedMaterials = newStash;
	}
	_inventory[idx] = NULL;
	++_unequipedMaterialsCount;
}

void	Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << _name << " cannot equip a NULL materia!" << std::endl;
		return ;
	}
	for (size_t i = 0; i < INVENTORY_SIZE; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m->clone();
			return ;
		}
	}
	std::cout << _name << ": inventory is full, cannot equip a new materia!" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= static_cast<int>(INVENTORY_SIZE)) {
		std::cout << _name << ": index out of inventory" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << _name << ": no materia equiped at " << idx << std::endl;
		return ;
	}
	saveUnequipedMaterial(idx);
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INVENTORY_SIZE) {
		std::cout << _name << ": index out of inventory" << std::endl;
	}
	if (_inventory[idx] == NULL) {
		std::cout << _name << ": no material at this index in current inventory" << std::endl;
	}
	_inventory[idx]->use(target);
}
