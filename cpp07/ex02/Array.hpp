/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:21:25 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/29 00:25:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class Array
{
    public:
        Array(void) : _data(NULL), _size(0){};

        Array(unsigned int size) : _data(NULL), _size(size)
        {
            this->_data = new T[size];
            unsigned int index = 0;

            while (index < size)
            {
                this->_data[index] = T();
                index++;
            }
        };

        Array(Array &copy)
        {
            unsigned int index = 0;

            this->_size = copy.getSize();
            this->_data = NULL;
            this->_data = new T[this->_size];
            while (index < this->_size)
            {
                this->_data[index] = copy[index];
                index++;
            }
        };

        Array<T> &operator=(Array const & copy)
        {
            unsigned int index = 0;
            if (this == &copy)
                return (this);
            this->_size = copy.getSize();
            if (this->_data != NULL)
                delete [] this->_data;
            this->_data = NULL;
            this->_data = new T[this->_size];
            while (index < this->_size)
            {
                this->_data[index] = copy[index];
                index++;
            }
            return (this);
        }

        T &operator[](unsigned int index)
        {
			if (index >= this->_size)
            	throw std::exception();
            else
			    return (_data[index]);
		}

        ~Array(void)
        {
            if (this->_data != NULL)
                delete [] _data;
        };

        unsigned int getSize(void) const
        {
            return (_size);
        };

        private:
            T *_data;
            unsigned int _size;
};

#endif /*ARRAY_HPP*/