/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat& temp);
        Cat& operator=(const Cat& temp);
        ~Cat();
        void makeSound(void) const;
        void printIdeas(void) const;

        std::string getIdea(int i) const;
        void setIdeas(std::string idea);
        void setIdeas(std::string idea, int i);

};

#endif /*Cat_HPP*/