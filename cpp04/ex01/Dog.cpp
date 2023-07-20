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
    std::cout << "Dog was created" << std::endl;
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::Dog(const Dog& temp) : Animal()
{
    int i;
    std::string temp_str;

    std::cout << "Dog was copied" << std::endl;
    this->type = temp.type;
    this->brain = new Brain;
    for (i = 0; i < 0; i++)
    {
        temp_str = temp.brain->getIdea(i);
        this->brain->setIdeas(temp_str, i);
    }
}

Dog &Dog::operator=(const Dog& temp)
{
    int i;
    std::string temp_str;

    std::cout << "Dog has been assigned" << std::endl;
    this->type = temp.type;
    this->brain = new Brain;
    for (i = 0; i < 0; i++)
    {
        temp_str = temp.brain->getIdea(i);
        this->brain->setIdeas(temp_str, i);
    }
    return (*this);
}

Dog::~Dog()
{
    delete (this->brain);
    std::cout << "Dog was destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound... Au Au..." << std::endl;
}

void Dog::printIdeas(void) const
{
    int index;
    std::string *ideas;

    ideas = this->brain->getIdeas();
    for (index = 0; index < 100; index++)
        std::cout << "[" << index << "]: " << ideas[index] << std::endl;
}

void Dog::setIdeas(std::string idea)
{
    this->brain->setIdeas(idea);
}

void Dog::setIdeas(std::string idea, int i)
{
    if (i < 0 || i > 99)
        return ;
    this->brain->setIdeas(idea, i);
}
