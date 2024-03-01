/**
 * @file 342.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/power-of-four/description/
 */

class Solution
{
public:
  bool isPowerOfFour(int n)
  {
    return n > 0 && 1073741824 % n == 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
  }
};