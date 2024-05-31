/**
 * @file 260.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-31
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
  int n = nums.size();
  int x = 0;
  for (int i = 0; i < n; i++)
  {
    x ^= nums[i];
  }
  int bit = 0;
  for (int i = 0; i < 32; i++)
  {
    if (x & (1 << i))
    {
      bit = i;
      break;
    }
  }
  int a = 0, b = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] & (1 << bit))
    {
      a ^= nums[i];
    }
    else
    {
      b ^= nums[i];
    }
  }
  return {a, b};
}

int main()
{
  vector<int> nums = {1, 2, 1, 3, 2, 5};
  vector<int> res = singleNumber(nums);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}