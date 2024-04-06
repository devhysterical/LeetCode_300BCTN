/**
 * @file 561.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/array-partition/description/
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  int arrayPairSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
    {
      sum += nums[i];
    }
    return sum;
  }
};