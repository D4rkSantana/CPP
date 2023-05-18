/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:21:23 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/17 00:47:41 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class PhoneBook{
	private:
		Contact	contats[8];
	
	public:
		PhoneBook()
		{
			std::cout << "Phonebook created" << std::endl;
		}
		~PhoneBook()
		{
			std::cout << "Phonebook destroed" << std::endl;
		}
		void	add_contact(Contact);
		void	del_contact(std::string);
		Contact	get_contacts(void);
};

void	add_contact(Contact);
void	del_contact(std::string);