/**
 * @file 303.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/range-sum-query-immutable/
 * Time complexity = O(n)
 * Space complexity = O(n)
 */

class NumArray
{
public:
    vector<int> prefixSum;
  NumArray(vector<int> &nums)
  {
    int n = nums.size();
    prefixSum.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
  }

  int sumRange(int left, int right)
  {
    return prefixSum[right + 1] - prefixSum[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */