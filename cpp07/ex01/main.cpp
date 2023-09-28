/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/28 12:27:37 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define SIZE_VAL 5

int main()
{
    int inteiros[SIZE_VAL] = {0, 1, 2, 3, 4};
    float flutuantes[SIZE_VAL] = {0.5, 1.5, 2.5, 3.5, 4.5};
    char letras[SIZE_VAL] = {'4', '2', '-', 'S', 'P'};
    std::string palavras[SIZE_VAL] = {"aaa", "bbb", "ccc", "ddd", "eee"};

    std::cout << "\n===== Teste com Int ======\n";
    iter(inteiros, SIZE_VAL, printGeneric<int>);

    std::cout << "\n===== Teste com Float ======\n";
    iter(flutuantes, SIZE_VAL, printGeneric<float>);

    std::cout << "\n===== Teste com Char ======\n";
    iter(letras, SIZE_VAL, printGeneric<char>);
    
    std::cout << "\n===== Teste com String ======\n";
    iter(palavras, SIZE_VAL, printGeneric<std::string>);

    return(0);
}
