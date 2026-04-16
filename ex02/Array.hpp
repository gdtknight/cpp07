/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
public:
  Array(void) : _array(NULL), _size(0)
  {
  }

  Array(unsigned int n) : _array(new T[n]()), _size(n)
  {
  }

  Array(Array const &other) : _array(NULL), _size(0)
  {
    *this = other;
  }

  ~Array(void)
  {
    delete[] _array;
  }

  Array &operator=(Array const &other)
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

  T &operator[](unsigned int index)
  {
    if (index >= _size)
      throw std::out_of_range("Array index out of bounds");
    return (_array[index]);
  }

  T const &operator[](unsigned int index) const
  {
    if (index >= _size)
      throw std::out_of_range("Array index out of bounds");
    return (_array[index]);
  }

  unsigned int size(void) const
  {
    return (_size);
  }

private:
  T *_array;
  unsigned int _size;
};

#endif
