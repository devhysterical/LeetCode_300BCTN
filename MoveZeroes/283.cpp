/**
 * @file 283.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-21
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/move-zeroes/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();
    int lastNonZeroFoundAt = 0;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] != 0)
      {
        nums[lastNonZeroFoundAt++] = nums[i];
      }
    }

    for (int i = lastNonZeroFoundAt; i < n; i++)
    {
      nums[i] = 0;
    }
  }
};
