/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:21:23 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/19 17:16:01 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact	contacts[8];
		int	pos;
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	print_contacts(void);
		//void	del_contact(std::string);
		//Contact	get_contacts(void);
};
