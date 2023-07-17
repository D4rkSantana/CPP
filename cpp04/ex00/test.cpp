/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:30 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/17 15:14:39 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    line(void)
{
    std::cout << "------------------------\n";
}

void    teste_animal(void)
{
    std::cout << "\n===== Teste Animal =====\n\n";
    Animal  *obj = new Animal();
    line();
    std::cout << "Type: " + obj->getType() + "\n";
    obj->makeSound();
    line();
    delete(obj);
}

void    teste_cat(void)
{
    std::cout << "\n===== Teste Cat ========\n\n";
    Animal  *obj = new Cat();
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

void    teste_wrong_animal(void)
{
    std::cout << "\n== Teste Wrong Animal ==\n\n";
    WrongAnimal *obj = new WrongAnimal();
    line();
    std::cout << "Type: " + obj->getType() + "\n";
    obj->makeSound();
    line();
    delete(obj);
}

void    teste_wrong_cat(void)
{
    std::cout << "\n=== Teste Wrong Cat ====\n\n";
    WrongAnimal *obj = new WrongCat();
    line();
    std::cout << "Type: " + obj->getType() + "\n";
    obj->makeSound();
    line();
    delete(obj);
}
