/**
 * @file 509.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/fibonacci-number/description/
 * Time complexity = O(2^n)
 * Space complexity = O(n)
 */

class Solution
{
public:
  int fib(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    if (n == 1)
    {
      return 1;
    }
    return fib(n - 1) + fib(n - 2);
  }
};