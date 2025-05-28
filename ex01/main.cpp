/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:42:19 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/26 18:42:54 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int	main(void) {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	//const WrongAnimal* i = new WrongCat();
// 	const Cat	Cat;

// 	std::cout << meta->getType() << " " << std::endl;
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	std::cout << Cat.getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	Cat.makeSound(); //idem
// 	j->makeSound(); // Dog sound
// 	meta->makeSound(); // Animal sound
// 	delete meta;
// 	delete j;
// 	delete i;
// 	return (EXIT_SUCCESS);
// }

int	main(void) {
	Animal*	animals[100];
	Cat	originalCat;
	Cat	copyCat(originalCat);
	Dog	originaDog;
	Dog	dogAffected;
	
	dogAffected = originaDog;
	originalCat.displayBrainLoc();
	copyCat.displayBrainLoc();
	originaDog.displayBrainLoc();
	dogAffected.displayBrainLoc();

	std::cout << std::endl << "-------------" << std::endl;
	for (size_t i = 0; i < 50; ++i) {
		animals[i] = new Cat();
	}
	for (size_t i = 50; i < 100; ++i) {
		animals[i] = new Dog();
	}
	for (size_t i = 0; i < 100; ++i) {
		delete animals[i];
	}
	return (EXIT_SUCCESS);
}
