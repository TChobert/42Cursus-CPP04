/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:57:45 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/28 14:58:17 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria {

	protected:

	std::string	_type;

	public:

	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria&	operator=(const AMateria& other);
	virtual ~AMateria(void);

	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);
};

#endif
