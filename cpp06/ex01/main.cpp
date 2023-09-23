/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:14:28 by esilva-s          #+#    #+#             */
/*   Updated: 2023/09/23 12:07:23 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static Data *init_data(void)
{
    Data *result = new (Data);

    result->name = "jorginho";
    result->weapon = "axe";
    result->hp = 1;
    result->lvl = 1;
    result->atk = 1;
    result->def = 1;
    return (result);
}

int main()
{
    Data *data = init_data();
    
    delete (data);
    return(0);
}
