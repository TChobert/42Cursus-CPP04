/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:58:35 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/03 14:59:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

///// CANONICAL /////

MateriaSource::MateriaSource(void) {
	initLearnedMateriasList();
	//std::cout << "MateriaSource: default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	copyLearnedMateriasList(other._learnedMateriasList);
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		destroyLearnedMateriasList();
		copyLearnedMateriasList(other._learnedMateriasList);
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	destroyLearnedMateriasList();
	//std::cout << "MateriaSource: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	MateriaSource::initLearnedMateriasList(void) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		_learnedMateriasList[i] = NULL;
	}
}

void	MateriaSource::copyLearnedMateriasList(const AMateria * const otherList[]) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (otherList[i] != NULL) {
			_learnedMateriasList[i] = otherList[i]->clone();
		}
	}
}

void	MateriaSource::destroyLearnedMateriasList(void) {
	for (size_t i; i < MATERIAS_NUMBER; ++i) {
		if (_learnedMateriasList[i] != NULL) {
			delete (_learnedMateriasList[i]);
			_learnedMateriasList[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *materia) {
	if (materia == NULL) {
		std::cout << "MateriaSource: impossible to learn an empty materia" << std::endl;
	}
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (_learnedMateriasList[i] != NULL) {
			_learnedMateriasList[i] = materia->clone();
			return ;
		}
	}
	std::cout << "MateriaSource: impossible to learn a new materia. List is full" << std::endl;
}
