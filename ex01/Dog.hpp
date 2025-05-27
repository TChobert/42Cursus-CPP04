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

class Dog : public Animal {

	private:

	Brain	*_brain;

	public:

	Dog(void);
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog(void);

	void	makeSound(void) const;
};

#endif
