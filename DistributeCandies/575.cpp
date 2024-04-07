/**
 * @file 575.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-07
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/distribute-candies/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution
{
public:
  int distributeCandies(vector<int> &candyType)
  {
    unordered_set<int> s;
    for (int i = 0; i < candyType.size(); i++)
    {
      s.insert(candyType[i]);
    }
    return min(s.size(), candyType.size() / 2);
  }
};