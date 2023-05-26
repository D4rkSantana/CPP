/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:21:19 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/26 19:13:49 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "main.hpp"

class Contact
{
	private:
		std::string	first_name;
		std::string last_name;
		std::string	nickname;
		std::string	number_phone;
		std::string	dark_secret;
		int			in_use;

	public:
		Contact();
		~Contact();
		std::string	get_first(void);
		std::string	get_last(void);
		std::string	get_nick(void);
		std::string	get_number(void);
		std::string	get_secret(void);
		int			get_status(void);
		void		edit(std::string vec[4]);
};

#endif
