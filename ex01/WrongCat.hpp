/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:55:53 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 14:56:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

	WrongCat(void);
	WrongCat(const WrongCat& other);
	WrongCat&	operator=(const WrongCat& other);
	~WrongCat(void);

	void	makeSound(void) const;
};

#endif
