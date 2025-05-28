/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:59:57 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/26 18:00:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

class Cat : public Animal {

	private:

	Brain	*_brain;

	public:

	Cat(void);
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	~Cat(void);

	void	makeSound(void) const;
	void	displayBrainLoc(void);
};

#endif
