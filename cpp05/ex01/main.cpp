/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/11 16:50:16 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void    primeiro_teste(void)
{
    std::cout << "\n======= Primeiro Teste =======\n";

    Form obj;
    Form obj1("Teste", 140, 110);
    Form obj2(obj1);

    std::cout << std::endl;

    try{
        Form obj3("Teste2", 100, 200);
    }
    catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << obj << std::endl;
    std::cout << obj1 << std::endl;
    std::cout << obj2 << std::endl;
}

void    segundo_teste(void)
{
    std::cout << "\n======= Segundo Teste ========\n";

    Bureaucrat bur("Beltrano", 100);
    Form form("Teste", 101, 10);

    std::cout << std::endl;

    bur.signForm(form);
    bur.incrementGrade();
    bur.signForm(form);
}

int main()
{
    primeiro_teste();
    segundo_teste();
    return(0);
}
