/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/26 21:51:42 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
    T aux = b;

    b = a;
    a = aux;
}

template <typename T>
T max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
}

template <typename T>
T min(T &a, T &b)
{
    if (a < b)
        return (a);
    return (b);
}

#endif /*WHATEVER_HPP*/