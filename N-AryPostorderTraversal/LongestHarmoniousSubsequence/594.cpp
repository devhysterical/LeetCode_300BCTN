/**
 * @file 594.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-07
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/longest-harmonious-subsequence/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      m[nums[i]]++;
    }
    int res = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
      if (m.find(it->first + 1) != m.end())
      {
        res = max(res, it->second + m[it->first + 1]);
      }
    }
    return res;
  }
};