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

int main(void) {

	// MateriaSource content init :

	std::cout << "------ MATERIA SOURCE INIT AND TESTING ------" << std::endl << std::endl;

	IMateriaSource* src = new MateriaSource();
	Ice	ice;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice(ice));
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	// Character deep copy test

	std::cout << std::endl << "------ CHARACTER DEEP COPY ------" << std::endl << std::endl;

	Character original("original");
	AMateria* tmp = src->createMateria("ice");
	original.equip(tmp);

	// Deep copy
	Character copy = original;

	// Vérifie que les deux ont des inventaires séparés
	original.unequip(0);
	copy.use(0, original); // doit encore fonctionner

	// Multiple Materias and characters creation and comportment

	std::cout << std::endl << "------ MULTIPLE CHARACTERS AND MATERIAS USAGE ------" << std::endl << std::endl;
	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	ICharacter* bob = new Character("bob");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->use(2, *bob);
	bob->unequip(0);
	bob->unequip(6);
	bob->use(0, *me);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	src->learnMateria(new Cure());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(2, *bob);
	me->unequip(2);
	me->use(2, *bob);

	tmp = src->createMateria("fire");
	if (!tmp)
		std::cout << "Correctly failed to create unknown materia" << std::endl;

	// clean

	std::cout << std::endl << "------ CLEANUP ------" << std::endl << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}

// int	main(void) {
// 	std::cout << "========== [ Set Materia ] ==========" << std::endl;
//     std::cout << "----------- [Create MateriaSource] --------------" << std::endl;
//     IMateriaSource* src = new MateriaSource();
    
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     std::cout << "\n========== [ Set Character A ] ==========" << std::endl;
//     std::cout << "----------- [Character : ME] --------------" << std::endl;
//     ICharacter* me = new Character("ME");
//     // Equip materias to the character (me)
//     std::cout << "\n========== [ TEST equip() ] ==========" << std::endl;
//     std::cout << "----------- [Equip on Character ME] --------------" << std::endl;
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("ice");//5th should fail!
//     me->equip(tmp);

//     std::cout << "----------- [Unequip on Character ME] --------------" << std::endl;
//     me->unequip(0);

//     tmp = src->createMateria("cure");//equip after unequip -> should work!
//     me->equip(tmp);


//     std::cout << "\n========== [ Set Character B ] ==========" << std::endl;
//     std::cout << "----------- [Character : BOB] --------------" << std::endl;
//     ICharacter* bob = new Character("BOB");
    
//     std::cout << "\n========== [ TEST use() ] ==========" << std::endl;
//     me->use(0, *bob);//cure
//     me->use(4, *bob);//ice

//     std::cout << "\n========== [ Cleanup ] ==========" << std::endl;

//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }

// int main()
// {
// 	Character	caract;
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("test");
// 	tmp = src->createMateria("ice");
// 	caract.equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, caract);
// 	caract.use(0, *me);

// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }
