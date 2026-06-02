/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int const &value)
{
  std::cout << value << std::endl;
}

void printString(std::string const &value)
{
  std::cout << value << std::endl;
}

void addOne(int &value)
{
  value += 1;
}

int main(void)
{
  int numbers[] = {1, 2, 3, 4, 5};
  std::string words[] = {"hello", "world", "cpp07"};
  int const constNumbers[] = {10, 20, 30};

  std::cout << "=== Int array ===" << std::endl;
  iter(numbers, 5, printInt);
  iter(numbers, 5, addOne);
  std::cout << "--- After addOne ---" << std::endl;
  iter(numbers, 5, printInt);

  std::cout << std::endl << "=== String array ===" << std::endl;
  iter(words, 3, printString);

  std::cout << std::endl << "=== Const int array ===" << std::endl;
  iter(constNumbers, 3, printInt);

  return (0);
}
