/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:29:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/20 02:45:19 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie{
	public:
	
		Zombie()
		{
			std::cout << "new zombie create" << std::endl;
		}
		~Zombie()
		{
			std::cout << this->name << " is dead" << std::endl;
		}
		void set_name(std::string);
    	void announce(void);

	private:
		std::string	name;
};

Zombie	*zombieHorde(int n, std::string name);
