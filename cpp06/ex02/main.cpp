/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/24 22:04:31 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
    Base *a = new (A);
    Base *b = new (B);
    Base *c = new (C);
    Base *randomic = generate();

    std::cout << std::endl << "Test A" << std::endl << std::endl;
    identify(a);
    identify(*a);

    std::cout << std::endl << "Test B" << std::endl << std::endl;
    identify(b);
    identify(*b);

    std::cout << std::endl << "Test C" << std::endl << std::endl;
    identify(c);
    identify(*c);

    std::cout << std::endl << "Test Random" << std::endl << std::endl;
    identify(randomic);
    identify(*randomic);

    return(0);
}

static int  randomic_choice(void)
{
    int number;

    std::srand(std::time(NULL));

    number = (std::rand() % 3) + 1;
    return (number);
}

Base *generate(void)
{
    Base *result = NULL;
    int choice = randomic_choice();

    if (choice == 1)
        result = new (A);
    else if (choice == 2)
        result = new (B);
    else if (choice == 3)
        result = new (C);
    return (result);
}

void identify(Base *p)
{
    std::cout << "Identify point" << std::endl;

    A *a_test = dynamic_cast<A *>(p);
    B *b_test = dynamic_cast<B *>(p);
    C *c_test = dynamic_cast<C *>(p);

    if (a_test != NULL)
        std::cout << "the pointer is an object A" << std::endl;
    else if (b_test != NULL)
        std::cout << "the pointer is an object B" << std::endl;
    else if (c_test != NULL)
        std::cout << "the pointer is an object C" << std::endl;
    else
        std::cout << "pointer is not a supported object" << std::endl;
}

void identify(Base &p)
{
    bool find = true;

    std::cout << "Identify ref" << std::endl;
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "the pointer is an object A" << std::endl;
    }
    catch (const std::exception& e)
    {
        find = false;
    }
    if (find)
        return ;

    try {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "the pointer is an object B" << std::endl;
        find = true;
    }
    catch (const std::exception& e)
    {    
        find = false;
    }
    if (find)
        return ;

    try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "the pointer is an object C" << std::endl;
        find = true;
    }
    catch (const std::exception& e)
    {
        find = false;
    }
        
    if (find)
        return ;
    std::cout << "pointer is not a supported object" << std::endl;
}
