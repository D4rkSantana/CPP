/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/19 15:06:53 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static void my_test(void)
{
    std::cout << "\n== Inicio dos Testes ===\n";
    teste_animal();
    std::cout << "\n========================\n";
    teste_cat();
    std::cout << "\n========================\n";
    teste_dog();
    std::cout << "\n========================\n";
    teste_wrong_animal();
    std::cout << "\n========================\n";
    teste_wrong_cat();
    std::cout << "\n========================\n";
}

static void subject_test(void)
{
    std::cout << "\n===== Subject test =====\n\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    line();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    line();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    line();
    delete(meta);
    delete(j);
    delete(i);
    std::cout << "\n========================\n";
}

static void subject_test_wrong(void)
{
    std::cout << "\n== Subject test Wrong ==\n\n";
    const WrongAnimal* meta = new WrongAnimal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    line();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    line();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    line();
    delete(meta);
    delete(j);
    delete(i);
    std::cout << "\n========================\n";
}

int main()
{
    my_test();
    std::cout << std::endl;
    subject_test();
    subject_test_wrong();
    return(0);
}
