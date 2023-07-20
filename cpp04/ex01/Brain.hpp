/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:00 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string *ideas;
    public:
        Brain();
        Brain(const Brain& temp);
        Brain& operator=(const Brain& temp);
        ~Brain();
        std::string *getIdeas(void) const;
};

#endif /*Brain_HPP*/