/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:29:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/20 01:28:54 by esilva-s         ###   ########.fr       */
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

Zombie	*newZombie(std::string name);
void	randomChump( std::string name);
Zombie	*zombieHorde(int N, std::string name);