/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:19:21 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/08 12:48:48 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

std::string	read_file(std::string file_name);
std::string replace(std::string str, std::string s1, std::string s2);
void        create_file(std::string file, std::string content);

#endif /* REPLACE_HPP */