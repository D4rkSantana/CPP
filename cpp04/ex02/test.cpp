/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:30 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/27 18:58:48 by esilva-s         ###   ########.fr       */
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
    int qt = 6;
    Animal  *obj[qt];

    std::cout << "\n---Alocando os Objetos--\n";
    for(i = 0; i < qt; i++)
    {
        std::cout << "\n--- Obj [" << i << "] ---" << std::endl;
        if (i % 2 == 0)
            obj[i] = new Dog;
        else
            obj[i] = new Cat;
    }
    std::cout << "\n-Desalocando os Objetos-\n";
    for(i = 0; i < qt; i++)
    {
        std::cout << "\n--- Obj [" << i << "] ---" << std::endl;
        delete obj[i];
    }
}
    
void    test_copy(void)
{
    int i;
    
    std::cout << "\n--------Objeto 1--------\n";
    Dog *obj1 = new Dog;
    
    for(i = 0; i < 10; i++)
        obj1->setIdeas("objeto", i);

    std::cout << "\n--------Objeto 2--------\n";
    Dog *obj2 = new Dog(*obj1);


    std::cout << "\n--------Ideas obj1------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 1 [" << i << "]: " << obj1->getIdea(i) << std::endl;
    std::cout << "\n--------Ideas obj2------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 2 [" << i << "]: " << obj2->getIdea(i) << std::endl;
    
    std::cout << "\n------Mudanca obj1------\n";
    for(i = 0; i < 10; i++)
        obj1->setIdeas("objeto errado", i);

    std::cout << "\n--------Ideas obj1------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 1 [" << i << "]: " << obj1->getIdea(i) << std::endl;
    std::cout << "\n--------Ideas obj2------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 2 [" << i << "]: " << obj2->getIdea(i) << std::endl;

    std::cout << "\n-------Delete Obj1------\n";
    delete obj1;
    std::cout << "\n-------Delete Obj2------\n";
    delete obj2;
}

void    test_assign(void)
{
    int i;
    
    std::cout << "\n--------Criacao---------\n";
    Dog *obj1 = new Dog;
    Dog *obj2 = new Dog;

    std::cout << "\n-------Dog ideias-------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 1 [" << i << "]: " << obj1->getIdea(i) << std::endl;
    std::cout << "\n-------Cat ideias-------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 2 [" << i << "]: " << obj2->getIdea(i) << std::endl;

    std::cout << "\n----Definindo Ideais----\n";
    for(i = 0; i < 10; i++)
        obj2->setIdeas("Teste funcionou", i);

    std::cout << "\n-------Atribuindo-------\n";
    *obj1 = *obj2;

    std::cout << "\n-------Dog ideias-------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 1 [" << i << "]: " << obj1->getIdea(i) << std::endl;
    std::cout << "\n-------Cat ideias-------\n";
    for(i = 0; i < 10; i++)
        std::cout << "objeto 2 [" << i << "]: " << obj2->getIdea(i) << std::endl;

    std::cout << "\n-------Delete Obj1------\n";
    delete obj1;
    std::cout << "\n-------Delete Obj2------\n";
    delete obj2;
}