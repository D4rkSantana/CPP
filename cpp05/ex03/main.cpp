/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/20 20:10:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Criando Funcionarios" << std::endl;
    Bureaucrat bur("frank", 1);
    std::cout << std::endl;
    Intern random;
    std::cout << std::endl;

    std::cout << "=== Criando Formularios" << std::endl;
    AForm *form;
    AForm *form2;
    form = random.makeForm("RobotomyRequestForm", "Afonso");
    std::cout << std::endl;
    
    try{
        form2 = random.makeForm("WrongForm", "wrong");
    }
    catch (std::exception &e)
    {
        form2 = NULL;
        std::cout << "Form not create because: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Assinando" << std::endl;
    bur.signForm(*form);
    std::cout << std::endl;
    std::cout << "=== Executando" << std::endl;
    bur.executeForm(*form);
    std::cout << std::endl;

    std::cout << "=== Delete" << std::endl;
    delete form;
    
    if (form2 != NULL)
        delete form;
    return(0);
}
