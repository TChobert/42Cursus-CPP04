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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	//const Animal* i = new Cat();
	const WrongAnimal* i = new WrongCat();
	const Cat	CatTest;
	Cat			AffectCat;
	Dog			CopyDog(*dynamic_cast<const Dog*>(j));

	AffectCat = CatTest;
	std::cout << meta->getType() << " " << std::endl; // Animal
	std::cout << j->getType() << " " << std::endl; // Dog
	std::cout << i->getType() << " " << std::endl; // WrongCat
	std::cout << CatTest.getType() << " " << std::endl; // Cat
	std::cout << AffectCat.getType() << " " << std::endl; // Cat
	std::cout << CopyDog.getType() << " " << std::endl; // Dog
	i->makeSound(); // will output the wrong cat sound!
	AffectCat.makeSound(); // Cat sound
	j->makeSound(); // Dog sound
	meta->makeSound(); // Animal sound
	CopyDog.makeSound(); // Dog Sound
	delete meta;
	delete j;
	delete i;
	return (EXIT_SUCCESS);
}
