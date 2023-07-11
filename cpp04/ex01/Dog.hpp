/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain   *brain;
    public:
        Dog();
        Dog(const Dog& temp);
        Dog& operator=(const Dog& temp);
        ~Dog();
        void makeSound(void) const;
        void printIdeas(void) const;
        std::string getIdea(int i) const;
        void setIdeas(std::string idea);
        void setIdeas(std::string idea, int i);
};

#endif /*Dog_HPP*/