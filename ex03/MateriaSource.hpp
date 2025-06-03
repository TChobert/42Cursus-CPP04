/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:50:51 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/03 14:51:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MATERIAS_NUMBER 4

class MateriaSource : public IMateriaSource {

	private:

	AMateria	*_materiasTemplates[4];
	void		initMateriasTemplates(void);
	void		destroyMateriasTemplates(void);
	void		copyMateriasTemplates(const AMateria * const otherList[]);

	public:

	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	MateriaSource&	operator=(const MateriaSource& other);
	~MateriaSource(void);
	void		learnMateria(AMateria *);
	AMateria	*createMateria(std::string const & type);
};

#endif
