/**
 * @file 338.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/counting-bits/description/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> bits(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      bits[i] = bits[i & (i - 1)] + 1;
    }
    return bits;
  }
};