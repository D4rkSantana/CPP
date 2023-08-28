/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <string>

class Template
{
    private:
    public:
        Template();
        Template(const Template& temp);
        Template& operator=(const Template& temp);
        ~Template();
};

std::ostream&   operator<<( std::ostream &out, const Template &ref)

#endif /*TEMPLATE_HPP*/