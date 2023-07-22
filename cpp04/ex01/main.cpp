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

static void my_test(void)
{
    std::cout << "\n== Inicio dos Testes ===\n";
    std::cout << "\n===== Teste Array ======\n";
    test_array();
    std::cout << "\n===== Teste Copy =======\n";
    test_copy();
    std::cout << "\n========================\n";
}

/*
static void subject_test(void)
{
    std::cout << "\n===== Subject test =====\n\n";
    const Animal* j = new Dog();
    line();
    const Animal* i = new Cat();
    line();
    delete j;
    line();
    delete i;
    std::cout << "\n========================\n";
}
*/

int main()
{
    my_test();
    std::cout << std::endl;
    //subject_test();
    return(0);
}
