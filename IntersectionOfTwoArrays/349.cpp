/**
 * @file 349.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/intersection-of-two-arrays/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    set<int> s(nums1.begin(), nums1.end());
    set<int> result;
    for (int num : nums2)
    {
      if (s.count(num))
      {
        result.insert(num);
      }
    }
    return vector<int>(result.begin(), result.end());
  }
};