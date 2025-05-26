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

int	main(void) {
	const Animal* meta = new Animal();
	//const Animal* j = new Dog();
	const Animal* i = new Cat();

	//std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	//j->makeSound();
	meta->makeSound();
	return (EXIT_SUCCESS);
}
