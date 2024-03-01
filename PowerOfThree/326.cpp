/**
 * @file 326.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/power-of-three/
 * Time complexity = O(1)
 * Space complexity = O(1)
 */

class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    return n > 0 && 1162261467 % n == 0;
  }
};