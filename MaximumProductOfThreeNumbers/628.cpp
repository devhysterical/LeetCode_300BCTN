/**
 * @file 628.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Time complexity = O(nlogn)
 * Space complexity = O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  cout << maximumProduct(nums) << endl;
  return 0;
}