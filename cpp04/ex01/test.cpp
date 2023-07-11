/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:30 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/11 18:11:11 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void    line(void)
{
    std::cout << "------------------------\n";
}

void    test_array(void)
{
    int i;
    Animal  *obj[10];

    std::cout << "---Alocando os Objetos--\n";
    for(i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            obj[i] = new Dog;
        else
            obj[i] = new Cat;
        line();
    }
    std::cout << "-Desalocando os Objetos-\n";
    for(i = 0; i < 10; i++)
    {
        delete obj[i];
        line();
    }
}
    
void    test_copy(void)
{
    int i;
    
    std::cout << "--------Objeto 1--------\n";
    Dog *obj1 = new Dog;
    
    for(i = 0; i < 10; i++)
        obj1->setIdeas("objeto", i);

    std::cout << "--------Objeto 2--------\n";
    Dog *obj2 = new Dog(*obj1);


    std::cout << "--------Ideas obj1------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 1 [" << i << "]: " << obj1->getIdea(i) << std::endl;
    std::cout << "--------Ideas obj2------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 2 [" << i << "]: " << obj2->getIdea(i) << std::endl;
    
    std::cout << "------Mudanca obj1------\n";
    for(i = 0; i < 10; i++)
        obj1->setIdeas("objeto errado", i);

    std::cout << "--------Ideas obj1------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 1 [" << i << "]: " << obj1->getIdea(i) << std::endl;
    std::cout << "--------Ideas obj2------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 2 [" << i << "]: " << obj2->getIdea(i) << std::endl;
}
