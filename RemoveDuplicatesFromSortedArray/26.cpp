// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
    {
      return 0;
    }
    int slow = 0;
    for (int fast = 1; fast < n; fast++)
    {
      if (nums[fast] != nums[slow])
      {
        slow++;
        nums[slow] = nums[fast];
      }
    }
    return slow + 1;
  }
};

/*
- Time Complexity: O(N)
- Space Complexity: O(1)
*/