/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:40:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/23 19:56:37 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{

	//HumanA
	std::cout << std::endl << "==== Teste HumanA ====" << std::endl;
	Weapon club_a = Weapon("crude spiked club");
	HumanA bob("Bob", club_a);

	bob.attack();
	club_a.setType("some other type of club");
	bob.attack();


	//HumanB
	std::cout << std::endl << "==== Teste HumanB ====" << std::endl;
	Weapon club_b = Weapon("crude spiked club");
	HumanB jim("Jim");
	
	jim.setWeapon(club_b);
	jim.attack();
	club_b.setType("some other type of club");
	jim.attack();
	std::cout << std::endl;
	
	std::cout << "==== Destroy all ====" << std::endl;
	
	return (1);
}
