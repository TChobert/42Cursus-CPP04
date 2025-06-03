/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:32:04 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/03 17:32:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"

int main() {

	IMateriaSource* src = new MateriaSource();
	Ice	ice;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	//src->learnMateria(&ice);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	src->learnMateria(new Cure());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(2, *bob);
	me->unequip(2);
	me->use(2, *bob);

	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}
