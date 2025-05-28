/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:56:15 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 13:57:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

class Dog : public Animal {

	private:

	Brain	*_brain;

	public:

	Dog(void);
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog(void);

	void	makeSound(void) const;
	void	displayBrainLoc(void) const;
};

#endif
