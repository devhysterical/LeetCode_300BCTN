/**
 * @file 598.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-24
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/range-addition-ii/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  int maxCount(int m, int n, vector<vector<int>> &ops)
  {
    for (auto &op : ops)
    {
      m = min(m, op[0]);
      n = min(n, op[1]);
    }
    return m * n;
  }
};