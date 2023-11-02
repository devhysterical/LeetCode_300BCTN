/*
https://leetcode.com/problems/two-sum/description/
*/
class Solution
{
public:
  /**
   * The function "twoSum" takes a vector of integers and a target integer, and returns a vector of two
   * integers that add up to the target.
   * 
   * @param nums A vector of integers that contains the input numbers.
   * @param target an integer value representing the target sum that we want to find using two numbers
   * from the given vector.
   * 
   * @return a vector of integers which contains the indices of the two numbers in the input vector
   * that add up to the target value. If no such pair is found, an empty vector is returned.
   */
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hash_table;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];
      if (hash_table.find(complement) != hash_table.end())
      {
        result.push_back(hash_table[complement]);
        result.push_back(i);
        return result;
      }
      hash_table[nums[i]] = i;
    }
    return result;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(n)
*/