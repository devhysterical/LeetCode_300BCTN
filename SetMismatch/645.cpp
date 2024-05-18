/**
 * @file 645.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/set-mismatch/description/
 * Time Complexity = O(n)
 * Space Complexity = O(1)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
  vector<int> res;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[abs(nums[i]) - 1] < 0)
    {
      res.push_back(abs(nums[i]));
    }
    else
    {
      nums[abs(nums[i]) - 1] *= -1;
    }
  }
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > 0)
    {
      res.push_back(i + 1);
    }
  }
  return res;
}

int main()
{
  vector<int> nums = {1, 2, 2, 4};
  vector<int> res = findErrorNums(nums);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  return 0;
}