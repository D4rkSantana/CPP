/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:38:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/04 17:18:09 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "======= DEBUG LEVEL ========" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    std::cout << "======= INFO LEVEL =========" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    std::cout << "======= WARNING LEVEL ======" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    std::cout << "======= ERROR LEVEL ========" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    return (0);
}