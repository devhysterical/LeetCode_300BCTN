/**
 * @file 350.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> count;
    for (int num : nums1)
    {
      count[num]++;
    }
    vector<int> result;
    for (int num : nums2)
    {
      if (count[num] > 0)
      {
        result.push_back(num);
        count[num]--;
      }
    }
    return result;
  }
};