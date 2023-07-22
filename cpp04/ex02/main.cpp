/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/11 18:10:53 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void my_test(int key)
{
    if (key == 0)
        return ;
    std::cout << "\n== Inicio dos Testes ===\n";
    std::cout << "\n===== Teste Array ======\n";
    test_array();
    std::cout << "\n===== Teste Copia ======\n";
    test_copy();
    std::cout << "\n========================\n";
}

/*
void    test_abstract(void)
{
    Animal *obj = new Cat;
    
    std::cout << obj->getType() << std::endl;
    obj->makeSound();

    Animal *obj2 = new Animal;

    std::cout << obj2->getType() << std::endl;
    obj2->makeSound();
}
*/

int main()
{
    //test_abstract();
    my_test(1);
    std::cout << std::endl;
    return(0);
}
