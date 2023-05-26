/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:58:30 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/26 19:20:29 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <string>
#include <cstring>

#include "Contact.hpp"
#include "PhoneBook.hpp"

void    print_headline(void);
void    print_line(int index, std::string fname, std::string lname, std::string nick);

#endif