// https://leetcode.com/problems/summary-ranges/

class Solution
{
public:
  std::vector<std::string> summaryRanges(std::vector<int> &nums)
  {
    std::vector<std::string> res;
    int n = nums.size();
    int start = 0;
    for (int i = 0; i < n; i++)
    {
      if (i == n - 1 || nums[i] + 1 != nums[i + 1])
      {
        if (start == i)
        {
          res.push_back(std::to_string(nums[start]));
        }
        else
        {
          std::string s = std::to_string(nums[start]) + "->" + std::to_string(nums[i]);
          res.push_back(s);
        }
        start = i + 1;
      }
    }
    return res;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
*/