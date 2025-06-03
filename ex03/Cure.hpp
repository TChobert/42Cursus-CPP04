/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:41:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/28 16:42:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

class Cure : public AMateria {

	public:

	Cure(void);
	Cure(const Cure& other);
	Cure&	operator=(const Cure& other);
	~Cure(void);

	virtual Cure*		clone(void) const;
	virtual void		use(ICharacter& target);
};

#endif
