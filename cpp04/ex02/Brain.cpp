/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:00 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    int index = 0;
    this->ideas = new std::string[100];
    while (index < 100)
    {
        this->ideas[index] = "ideas"; 
        index++;
    }
    std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain& temp)
{
    this->ideas = temp.getIdeas();
    std::cout << "Brain was copied" << std::endl;
}

Brain &Brain::operator=(const Brain& temp)
{   
    this->ideas = temp.getIdeas();
    std::cout << "Brain has been assigned" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    delete [] (this->ideas);
    std::cout << "Brain was destroyed" << std::endl;
}

std::string *Brain::getIdeas(void) const
{
    return(this->ideas);
}

std::string Brain::getIdea(int i) const
{
    if (i < 0 || i > 99)
        return ("");
    return(this->ideas[i]);
}

void Brain::setIdeas(std::string idea)
{
    int i;

    for(i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

void Brain::setIdeas(std::string idea, int i)
{
    this->ideas[i] = idea;
}
