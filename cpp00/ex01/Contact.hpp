/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:21:19 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/18 20:25:38 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	name;
		std::string	number_phone;

	public:
		Contact()
		{
			std::cout << "New contact void created" << std::endl;
		}
		Contact(std::string name, std::string number_phone)
		{
			this->name = name;
			this->number_phone = number_phone;
			std::cout << "New contact " << name << " created" << std::endl;
		}
		~Contact()
		{
			std::cout << "Contact destroyd" << std::endl;
		}
		std::string	get_name(void);
		std::string	get_number(void);
};