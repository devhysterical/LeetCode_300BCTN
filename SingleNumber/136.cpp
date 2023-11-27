/*
https://leetcode.com/problems/single-number/description/

- Time complexity: O(n)
- Space complexity: O(1)
*/
class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int result = 0;
    for (int num : nums)
    {
      result ^= num;
    }
    return result;
  }
};