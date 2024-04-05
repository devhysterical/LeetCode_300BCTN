/**
 * @file 541.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/reverse-string-ii/description/
 * Time complexity = O(n)
 * Space complexity = O(1)
 */

class Solution
{
public:
  string reverseStr(string a, int k)
  {
    int n = a.size();
    for (int i = 0; i < n; i += 2 * k)
    {
      reverse(a.begin() + i, a.begin() + min(i + k, n));
    }
    return a;
  }
};