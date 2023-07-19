/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "animal";
    std::cout << "Animal was created" << std::endl;
}

Animal::Animal(const Animal& temp)
{
    *this = temp;
    std::cout << "Animal was copied" << std::endl;
}

Animal &Animal::operator=(const Animal& temp)
{
    this->type = temp.type;
    std::cout << "Animal has been assigned" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal was destroyed" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound... ???..." << std::endl;
}