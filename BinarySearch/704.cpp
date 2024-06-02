/**
 * @file 704.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/binary-search/description/
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
  int left = 0, right = nums.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int main()
{
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  cout << search(nums, target) << endl;
  return 0;
}