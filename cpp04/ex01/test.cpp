/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:30 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/20 16:15:36 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    line(void)
{
    std::cout << "------------------------\n";
}

void    teste_cat(void)
{
    std::cout << "\n===== Teste Cat ========\n\n";
    Animal  *obj = new Cat();
    obj->setIdeas("objeto 1");
    line();
    std::cout << "Type: " + obj->getType() + "\n";
    obj->makeSound();
    line();
    delete(obj);
}

void    teste_dog(void)
{
    std::cout << "\n===== Teste Dog ========\n\n";
    Animal  *obj = new Dog();
    line();
    std::cout << "Type: " + obj->getType() + "\n";
    obj->makeSound();
    line();
    delete(obj);
}
