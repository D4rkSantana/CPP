/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& temp)
{
    *this = temp;
    std::cout << "WrongAnimal was copied" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& temp)
{
    this->type = temp.type;
    std::cout << "WrongAnimal has been assigned" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal was destroyed" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound... Wrong..." << std::endl;
}
