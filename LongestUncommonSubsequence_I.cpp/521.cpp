/**
 * @file 521.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/longest-uncommon-subsequence-i/description/
 * Time complexity = O(1)
 * Space complexity = O(1)
 */

class Solution
{
public:
  int findLUSlength(string a, string b)
  {
    if (a == b)
    {
      return -1;
    }
    else
    {
      return max(a.size(), b.size());
    }
  }
};