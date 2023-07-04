/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/04 16:04:10 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	print_line()
{
	std::cout << "=========================" << std::endl;
}

int	main()
{
	int		index;
	int		nb_horde;
	Zombie	*horde;

	index = 0;
	nb_horde = 10;
	std::cout << std::endl << "==== Create Horde ===="<< std::endl;	
	horde = zombieHorde(nb_horde, "Cobaia");
	print_line();
	std::cout << std::endl << "=== Announce Horde ==="<< std::endl;	
	while (index < nb_horde)
	{
		std::cout << "- Zombie: " << index << std::endl;
		horde[index].announce();
		index++;
	}
	print_line();
	std::cout << std::endl << "=== Destroy Horde ==="<< std::endl;	
	delete [] horde;
	print_line();
	std::cout << std::endl;
	return (1);
}
