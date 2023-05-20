/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:21:19 by esilva-s          #+#    #+#             */
/*   Updated: 2023/05/19 17:38:20 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	name;
		std::string last_name;
		std::string	nickname;
		std::string	number_phone;
		int			in_use;

	public:
		Contact();
		~Contact();
		std::string	get_name(void);
		std::string	get_number(void);
		int			get_status(void);
		void		edit(std::string vec[4]);
};