/**
 * @file 674.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int findLengthOfLCIS(vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
  {
    return 0;
  }
  int ans = 1, count = 1;
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > nums[i - 1])
    {
      count++;
    }
    else
    {
      ans = max(ans, count);
      count = 1;
    }
  }
  ans = max(ans, count);
  return ans;
}

int main()
{
  vector<int> nums = {1, 3, 5, 4, 7};
  cout << findLengthOfLCIS(nums) << endl;
  return 0;
}