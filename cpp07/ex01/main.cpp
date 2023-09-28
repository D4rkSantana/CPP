/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/27 21:17:48 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    size_t size = 5;

    int inteiros[size] = {0, 1, 2, 3, 4};
    float flutuantes[size] = {0.5, 1.5, 2.5, 3.5, 4.5};
    char letras[size] = {'4', '2', '-', 'S', 'P'};
    std::string palavras[size] = {"aaa", "bbb", "ccc", "ddd", "eee"};

    std::cout << "\n===== Teste com Int ======\n";
    iter(inteiros, size, printGeneric<int>);

    std::cout << "\n===== Teste com Float ======\n";
    iter(flutuantes, size, printGeneric<float>);

    std::cout << "\n===== Teste com Char ======\n";
    iter(letras, size, printGeneric<char>);
    
    std::cout << "\n===== Teste com String ======\n";
    iter(palavras, size, printGeneric<std::string>);

    return(0);
}
