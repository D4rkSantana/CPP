/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog was created" << std::endl;
}

Dog::Dog(const Dog& temp) : Animal()
{
    *this = temp;
    std::cout << "Dog was copied" << std::endl;
}

Dog &Dog::operator=(const Dog& temp)
{
    this->type = temp.type;
    std::cout << "Dog has been assigned" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog was destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound... Au Au..." << std::endl;
}
