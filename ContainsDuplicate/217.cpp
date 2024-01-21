/*
https://leetcode.com/problems/contains-duplicate/description/

- Time complexity: O(n)
- Space complexity: O(n)
*/

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_set<int> uniqueElements;

    for (int num : nums)
    {
      if (uniqueElements.find(num) != uniqueElements.end())
      {
        return true;
      }
      uniqueElements.insert(num);
    }
    return false;
  }
};