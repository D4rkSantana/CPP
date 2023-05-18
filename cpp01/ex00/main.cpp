/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/20 01:09:57 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie		*zombie;

	std::cout << std::endl << "==== Teste newZombie ===="<< std::endl;	
	zombie = newZombie("Crocodile");
	zombie->announce();
	delete zombie;
	std::cout << "=========================" << std::endl;


	std::cout << std::endl << "=== Teste randomChump ==="<< std::endl;	
	randomChump("Twisted Fate");
	std::cout << "=========================" << std::endl << std::endl;

	return (1);
}