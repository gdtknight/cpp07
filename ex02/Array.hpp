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
  Array(void);
  Array(unsigned int n);
  Array(Array const &other);
  ~Array(void);

  Array &operator=(Array const &other);

  T &operator[](unsigned int index);
  T const &operator[](unsigned int index) const;

  unsigned int size(void) const;

private:
  T *_array;
  unsigned int _size;
};

# ifndef ARRAY_TPP
#  include "Array.tpp"
# endif

#endif
