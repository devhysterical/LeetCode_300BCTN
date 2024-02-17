/**
 * @file 268.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-17
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/missing-number/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int missing = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
      missing ^= i ^ nums[i];
    }
    return missing;
  }
};