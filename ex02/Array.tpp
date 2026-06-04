/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# ifndef ARRAY_HPP
#  include "Array.hpp"
# endif

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other) : _array(NULL), _size(0)
{
  *this = other;
}

template <typename T>
Array<T>::~Array(void)
{
  delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
  if (this != &other)
  {
    delete[] _array;
    _size = other._size;
    if (_size > 0)
    {
      _array = new T[_size]();
      for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
    }
    else
      _array = NULL;
  }
  return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
  if (index >= _size)
    throw std::out_of_range("Array index out of bounds");
  return (_array[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
  if (index >= _size)
    throw std::out_of_range("Array index out of bounds");
  return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
  return (_size);
}

#endif
