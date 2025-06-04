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
	std::cout << BLUE << "MateriaSource: default constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	initMateriasTemplates();
	copyMateriasTemplates(other._materiasTemplates);
	std::cout << BLUE << "MateriaSource: copy constructor called" << RESET << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		destroyMateriasTemplates();
		copyMateriasTemplates(other._materiasTemplates);
	}
	std::cout << BLUE << "MateriaSource: assignement operator called" << RESET << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	destroyMateriasTemplates();
	std::cout << BLUE << "MateriaSource: destructor called" << RESET << std::endl;
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
		std::cout << BLUE << "MateriaSource: impossible to learn an empty materia" << RESET <<std::endl;
		return ;
	}
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (_materiasTemplates[i] == NULL) {
			_materiasTemplates[i] = materia;
			return ;
		}
	}
	std::cout << BLUE << "MateriaSource: impossible to learn a new materia. List is full" << RESET << std::endl;
	delete (materia);
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < MATERIAS_NUMBER; ++i) {
		if (_materiasTemplates[i] != NULL && _materiasTemplates[i]->getType() == type) {
			return (_materiasTemplates[i]->clone());
		}
	}
	std::cout << BLUE << "MateriaSource: cannot create a nonexistent materia type" << RESET << std::endl;
	return (0);
}
