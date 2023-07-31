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

void    primeiro_teste(void)
{
    std::cout << "\n======= Primeiro Teste =======\n";

    Bureaucrat obj; //O Objeto é gerado com o nome Frank e a classificação 150

    std::cout << "\nName: " << obj.getName() << " Grade: " << obj.getGrade() << std::endl;

    try{
        obj.decrementGrade();
    }
    catch (std::exception & e){
        std::cout << "= Decrement Error\n";
        std::cout << e.what() << std::endl;
    }
    try{
        obj.incrementGrade();
    }
    catch (std::exception & e){
        std::cout << "= Increment Error\n";
        std::cout << e.what() << std::endl;
    }

    std::cout << obj << std::endl;

}

void    segundo_teste(void)
{
    std::cout << "\n======= Segundo Teste ========\n";

    Bureaucrat obj("Beltrano", 1);

    std::cout << "\nName: " << obj.getName() << " Grade: " << obj.getGrade() << std::endl;

    try{
        obj.incrementGrade();
    }
    catch (std::exception & e){
        std::cout << "= Increment Error\n";
        std::cout << e.what() << std::endl;
    }

    try{
        obj.decrementGrade();
    }
    catch (std::exception & e){
        std::cout << "= Decrement Error\n";
        std::cout << e.what() << std::endl;
    }

    std::cout << obj << std::endl;
}

void    terceiro_teste(void)
{
    std::cout << "\n====== Terceiro Teste ========\n";

    try{
        Bureaucrat obj("Ciclano", 151);
    }
    catch (std::exception & e){
        std::cout << "= Constructor Error\n";
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    primeiro_teste();
    segundo_teste();
    terceiro_teste();
    return(0);
}
