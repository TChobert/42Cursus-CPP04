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

class Brain {

	private:

	std::string	_ideas[100];

	public:

	Brain(void);
	Brain(const Brain& other);
	Brain&	operator=(const Brain& other);
	~Brain(void);
};

#endif
