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
    std::cout << "Cat was created" << std::endl;
    this->type = "Cat";
    this->brain = new Brain;
}

Cat::Cat(const Cat& temp) : Animal()
{
    int i;
    std::string temp_str;

    std::cout << "Cat was copied" << std::endl;
    this->type = temp.type;
    this->brain = new Brain;
    for (i = 0; i < 0; i++)
    {
        temp_str = temp.brain->getIdea(i);
        this->brain->setIdeas(temp_str, i);
    }
}

Cat &Cat::operator=(const Cat& temp)
{
    int i;
    std::string temp_str;

    std::cout << "Cat has been assigned" << std::endl;
    this->type = temp.type;
    this->brain = new Brain;
    for (i = 0; i < 0; i++)
    {
        temp_str = temp.brain->getIdea(i);
        this->brain->setIdeas(temp_str, i);
    }
    std::cout << "Cat has been assigned" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete (this->brain);
    std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound... Miau..." << std::endl;
}

void Cat::printIdeas(void) const
{
    int index;
    std::string *ideas;

    ideas = this->brain->getIdeas();
    for (index = 0; index < 100; index++)
        std::cout << "[" << index << "]: " << ideas[index] << std::endl;
}

std::string Cat::getIdea(int i) const
{
    std::string idea;

    idea = this->brain->getIdea(i);
    return (idea);
}

void Cat::setIdeas(std::string idea)
{
    this->brain->setIdeas(idea);
}

void Cat::setIdeas(std::string idea, int i)
{
    if (i < 0 || i > 99)
        return ;
    this->brain->setIdeas(idea, i);
}
