/**
 * @file 292.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-21
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/nim-game/
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  bool canWinNim(int n)
  {
    return n % 4 != 0;
  }
};