/**
 * @file 697.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/degree-of-an-array/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int findShortestSubArray(vector<int> &nums)
{
  unordered_map<int, vector<int>> mp;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (mp.find(nums[i]) == mp.end())
    {
      mp[nums[i]] = {1, i, i};
    }
    else
    {
      mp[nums[i]][0]++;
      mp[nums[i]][2] = i;
    }
  }
  int degree = 0;
  for (auto it : mp)
  {
    degree = max(degree, it.second[0]);
  }
  int ans = n;
  for (auto it : mp)
  {
    if (it.second[0] == degree)
    {
      ans = min(ans, it.second[2] - it.second[1] + 1);
    }
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 2, 3, 1};
  cout << findShortestSubArray(nums) << endl;
  return 0;
}