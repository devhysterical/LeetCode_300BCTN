/**
 * @file 367.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/valid-perfect-square/description/
 * Time complexity: O(logn)
 * Space complexity: O(1)
 */

class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    long left = 1, right = num;
    while (left <= right)
    {
      long middle = left + (right - left) / 2;
      if (middle * middle == num)
      {
        return true;
      }
      else if (middle * middle < num)
      {
        left = middle + 1;
      }
      else
      {
        right = middle - 1;
      }
    }
    return false;
  }
};