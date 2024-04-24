/**
 * @file 1137.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-24
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  int tribonacci(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    if (n == 1 || n == 2)
    {
      return 1;
    }
    int a = 0, b = 1, c = 1, d;
    for (int i = 3; i <= n; i++)
    {
      d = a + b + c;
      a = b;
      b = c;
      c = d;
    }
    return c;
  }
};