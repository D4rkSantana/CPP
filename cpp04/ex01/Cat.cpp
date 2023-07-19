/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat was created" << std::endl;
}

Cat::Cat(const Cat& temp) : Animal()
{
    *this = temp;
    std::cout << "Cat was copied" << std::endl;
}

Cat &Cat::operator=(const Cat& temp)
{
    this->type = temp.type;
    std::cout << "Cat has been assigned" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound... Miau..." << std::endl;
}