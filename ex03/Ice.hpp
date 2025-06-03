/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:18:18 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/28 15:19:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

class Ice : public AMateria {

	public:

	Ice(void);
	Ice(const Ice& other);
	Ice&	operator=(const Ice& other);
	~Ice(void);
	virtual Ice*	clone(void) const;
	virtual void	use(ICharacter& target);
};

#endif
