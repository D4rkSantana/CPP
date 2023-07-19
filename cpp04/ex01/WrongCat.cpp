/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/17 15:20:02 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& temp) : WrongAnimal()
{
    *this = temp;
    std::cout << "WrongCat was copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& temp)
{
    this->type = temp.type;
    std::cout << "WrongCat has been assigned" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat was destroyed" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sound... Monday left me broken..." << std::endl;
}