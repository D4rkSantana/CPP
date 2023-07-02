/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s < esilva-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:21:23 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/02 19:13:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "Contact.hpp"

std::string	catch_arg(void);
bool		empyt_check(std::string vec[], int size);
int			str_isdigit(const char *str);
void		print_div(void);
void		print_headline(void);
void		print_line(int index, std::string fname, std::string lname, std::string nick);

class PhoneBook{
	private:
		Contact	contacts[8];
		int		pos;
		int		print_contacts();
		void	print_search(int index);
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	search_contact(void);
};

#endif
