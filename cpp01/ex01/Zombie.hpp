/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:29:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/04 15:30:48 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie{
	public:
	
		Zombie();
		~Zombie();
		void setName(std::string);
    	void announce(void);

	private:
		std::string	name;
};

Zombie	*zombieHorde(int n, std::string name);
