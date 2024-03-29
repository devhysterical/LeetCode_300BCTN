/**
 * @file 2962.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-29
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2024-03-29
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  long long countSubarrays(vector<int> &nums, int k)
  {
    long long int max_num = *max_element(nums.begin(), nums.end()), count = 0;
    long long int left = 0, right = 0, ans = 0;
    while (right < nums.size() || left > right)
    {
      if (nums[right] == max_num)
        count++;
      while (count >= k)
      {
        if (nums[left] == max_num)
          count--;
        left++;
        ans += nums.size() - right;
      }
      right++;
    }
    return ans;
  }
};