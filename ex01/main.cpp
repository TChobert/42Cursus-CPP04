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

int	main(void) {
	Animal*	animals[100];
	Cat	originalCat;
	Cat	copyCat(originalCat);
	Dog	originalDog;
	Dog	dogAffected;
	
	dogAffected = originalDog;
	originalCat.displayBrainLoc();
	copyCat.displayBrainLoc();
	originalDog.displayBrainLoc();
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
