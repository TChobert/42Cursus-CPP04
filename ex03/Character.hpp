/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:28:01 by tchobert          #+#    #+#             */
/*   Updated: 2025/06/02 14:28:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

# define INVENTORY_SIZE 4

class Character : public ICharacter {

	private:

	std::string	_name;
	AMateria	*_inventory[4];
	AMateria	**_unequipedMaterials;
	size_t		_unequipedMaterialsCount;
	void		setInventory(void);
	void		deleteInventory(void);
	void		copyInventory(AMateria * const otherInventory[]);
	void		copyUnequipedMaterials(AMateria * const otherUnequipMaterials[]);
	void		saveUnequipedMaterial(int idx);
	void		deleteUnequipedMaterials(void);

	public:

	Character(void);
	Character(const std::string& name);
	Character(const Character& other);
	Character&	operator=(const Character& other);
	~Character(void);

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
	std::string const&	getName(void) const;
};

#endif
