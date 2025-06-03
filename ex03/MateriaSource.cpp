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
	initMateriasTemplates();
	//std::cout << "MateriaSource: default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	initMateriasTemplates();
	copyMateriasTemplates(other._materiasTemplates);
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		destroyMateriasTemplates();
		copyMateriasTemplates(other._materiasTemplates);
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	destroyMateriasTemplates();
	//std::cout << "MateriaSource: destructor called" << std::endl;
}

///// MEMBERS FUNCTIONS /////

void	MateriaSource::initMateriasTemplates(void) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		_materiasTemplates[i] = NULL;
	}
}

void	MateriaSource::copyMateriasTemplates(const AMateria * const otherList[]) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (otherList[i] != NULL) {
			_materiasTemplates[i] = otherList[i]->clone();
		}
	}
}

void	MateriaSource::destroyMateriasTemplates(void) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (_materiasTemplates[i] != NULL) {
			delete (_materiasTemplates[i]);
			_materiasTemplates[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *materia) {
	if (materia == NULL) {
		std::cout << "MateriaSource: impossible to learn an empty materia" << std::endl;
		return ;
	}
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (_materiasTemplates[i] == NULL) {
			_materiasTemplates[i] = materia->clone();
			delete (materia);
			return ;
		}
	}
	std::cout << "MateriaSource: impossible to learn a new materia. List is full" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (_materiasTemplates[i] != NULL && _materiasTemplates[i]->getType() == type) {
			return (_materiasTemplates[i]->clone());
		}
	}
	std::cout << "MateriaSource: cannot learn a nonexistent materia" << std::endl;
	return (0);
}
