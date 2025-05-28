/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:02:20 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/27 16:02:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define BLUE "\x1B[34m"
# define RESET "\x1B[0m"

class Brain {

	private:

	std::string	_ideas[100];

	public:

	Brain(void);
	Brain(const Brain& other);
	Brain&	operator=(const Brain& other);
	~Brain(void);

	size_t			getIdeasSize(void) const;
	std::string		getIdea(size_t index) const;
	void			displayIdeasFirstAddress(void) const;
};

#endif
