/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:38:57 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 14:39:33 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {

	protected:

	std::string	_type;

	public:

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator=(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	void				setType(const std::string& type);
	const std::string&	getType(void) const;
	virtual void		makeSound(void) const;
};

#endif
