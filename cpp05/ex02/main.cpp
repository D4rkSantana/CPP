/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:56:39 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    teste_nao_funcional(AForm &form)
{
    std::cout << "---" << std::endl;
    Bureaucrat bur("Leon", 150);
    std::cout << "---" << std::endl;

    std::cout << "- execução:" << std::endl;
    bur.executeForm(form);
    std::cout << "---" << std::endl;

    std::cout << "- fim:" << std::endl;
}

void    teste_funcional(AForm &form)
{
    std::cout << "---" << std::endl;
    Bureaucrat bur("Frank", 1);
    std::cout << "---" << std::endl;

    std::cout << "- assinatura:" << std::endl;
    bur.signForm(form);
    std::cout << "---" << std::endl;

    std::cout << "- execução:" << std::endl;
    bur.executeForm(form);
    std::cout << "---" << std::endl;

    std::cout << "- fim:" << std::endl;
}

int main()
{
    std::cout << "===== Inicio " << std::endl;
    
    std::cout << "===== Teste Shrubbery "<< std::endl;
    ShrubberyCreationForm form1("Tree");
    teste_funcional(form1);
    std::cout << std::endl;

    std::cout << "===== Teste Shrubbery Error "<< std::endl;
    teste_nao_funcional(form1);
    std::cout << std::endl;
    
    std::cout << "===== Teste Robotomy "<< std::endl;
    RobotomyRequestForm form2("Rick");
    teste_funcional(form2);
    std::cout << std::endl;

    std::cout << "===== Teste Robotomy Erro"<< std::endl;
    teste_nao_funcional(form2);
    std::cout << std::endl;

    std::cout << "===== Teste PresidentialPardon "<< std::endl;
    PresidentialPardonForm form3("Vick");
    teste_funcional(form3);
    std::cout << std::endl;

    std::cout << "===== Teste PresidentialPardon Erro"<< std::endl;
    teste_nao_funcional(form3);
    std::cout << std::endl;

    return(0);
}
