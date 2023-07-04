/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:27:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/04 15:31:01 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	int		index;
	Zombie	*horde;

	if (n < 1)
		return (0);
	index = 0;
	horde = new Zombie[n];
	while (index < n)
	{
		horde[index].setName(name);
		index++;
	}
	return (horde);
}
