/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& temp);
        Animal& operator=(const Animal& temp);
        virtual ~Animal();
        virtual std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif /*Animal_HPP*/