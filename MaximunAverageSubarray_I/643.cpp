/**
 * @file 643.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/maximum-average-subarray-i/description/
 * Time Complexity = O(n)
 * Space Complexity = O(1)
 */

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
  double sum = 0;
  for (int i = 0; i < k; i++)
  {
    sum += nums[i];
  }
  double res = sum;
  for (int i = k; i < nums.size(); i++)
  {
    sum += nums[i] - nums[i - k];
    res = max(res, sum);
  }
  return res / k;
}

int main() {
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  cout << findMaxAverage(nums, k) << endl;
  return 0;
}