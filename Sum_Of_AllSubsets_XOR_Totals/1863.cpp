/**
 * @file 1863.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20
 * Time Complexity: O(2^n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int subsetXORSum(vector<int> &nums)
{
  int n = nums.size();
  int total = 1 << n;
  int sum = 0;
  for (int i = 0; i < total; i++)
  {
    int xorSum = 0;
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        xorSum ^= nums[j];
      }
    }
    sum += xorSum;
  }
  return sum;
}

int main()
{
  vector<int> nums = {1, 3};
  cout << subsetXORSum(nums) << endl;
  return 0;
}