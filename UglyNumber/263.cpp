/**
 * @file 263.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-17
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/ugly-number/description/
 * Time complexity: O(logn)
 * Space complexity: O(1)
 */

class Solution
{
public:
  bool isUgly(int n)
  {
    if (n <= 0) return false;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
  }
};