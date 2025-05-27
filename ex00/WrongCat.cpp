/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:01:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 15:01:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) :WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	this->_type = other._type;
	std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		this->_type = other._type;
		std::cout << "WrongCat: assignement operator called" << std::endl;
	}
	return (*this);
}
