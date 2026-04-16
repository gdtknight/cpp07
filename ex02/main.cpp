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

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
  std::cout << "=== Test 1: Empty array ===" << std::endl;
  {
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try
    {
      empty[0];
    }
    catch (std::exception &e)
    {
      std::cout << "Exception on empty array: " << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "=== Test 2: Int array ===" << std::endl;
  {
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
      arr[i] = i * 10;
      std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
  }

  std::cout << std::endl << "=== Test 3: Deep copy (copy constructor) ===" << std::endl;
  {
    Array<int> original(3);
    original[0] = 42;
    original[1] = 21;
    original[2] = 84;

    Array<int> copy(original);
    copy[0] = 0;
    std::cout << "original[0] = " << original[0] << " (should be 42)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (should be 0)" << std::endl;
  }

  std::cout << std::endl << "=== Test 4: Deep copy (assignment) ===" << std::endl;
  {
    Array<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    Array<int> b;
    b = a;
    b[0] = 100;
    std::cout << "a[0] = " << a[0] << " (should be 1)" << std::endl;
    std::cout << "b[0] = " << b[0] << " (should be 100)" << std::endl;
    std::cout << "b.size() = " << b.size() << " (should be 3)" << std::endl;
  }

  std::cout << std::endl << "=== Test 5: Out of bounds ===" << std::endl;
  {
    Array<int> arr(3);
    try
    {
      arr[3];
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
      arr[100];
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "=== Test 6: String array ===" << std::endl;
  {
    Array<std::string> arr(3);
    arr[0] = "Hello";
    arr[1] = "World";
    arr[2] = "42";
    for (unsigned int i = 0; i < arr.size(); i++)
      std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
  }

  std::cout << std::endl << "=== Test 7: Const array ===" << std::endl;
  {
    Array<int> arr(2);
    arr[0] = 10;
    arr[1] = 20;

    Array<int> const constArr(arr);
    std::cout << "constArr[0] = " << constArr[0] << std::endl;
    std::cout << "constArr[1] = " << constArr[1] << std::endl;
    std::cout << "constArr.size() = " << constArr.size() << std::endl;
  }

  return (0);
}
