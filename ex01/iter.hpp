/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T &))
{
  for (std::size_t i = 0; i < length; i++)
    func(array[i]);
}

template <typename T>
void iter(T const *array, std::size_t length, void (*func)(T const &))
{
  for (std::size_t i = 0; i < length; i++)
    func(array[i]);
}

#endif
