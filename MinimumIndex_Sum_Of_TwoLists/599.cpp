/**
 * @file 599.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-26
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution
{
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
  {
    unordered_map<string, int> m;
    vector<string> res;
    int minSum = INT_MAX;
    for (int i = 0; i < list1.size(); i++)
    {
      m[list1[i]] = i;
    }
    for (int i = 0; i < list2.size(); i++)
    {
      if (m.count(list2[i]))
      {
        int sum = i + m[list2[i]];
        if (sum < minSum)
        {
          res.clear();
          res.push_back(list2[i]);
          minSum = sum;
        }
        else if (sum == minSum)
        {
          res.push_back(list2[i]);
        }
      }
    }
    return res;
  }
};