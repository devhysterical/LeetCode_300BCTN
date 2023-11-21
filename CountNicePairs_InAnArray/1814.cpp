/*
https://leetcode.com/problems/count-nice-pairs-in-an-array/description/?envType=daily-question&envId=2023-11-21
*/
class Solution
{
public:
  int countNicePairs(vector<int> &nums)
  {
    const int MOD = 1e9 + 7;
    unordered_map<int, int> countMap;
    int nicePairs = 0;

    for (int num : nums)
    {
      int revDiff = num - reverseNumber(num);
      nicePairs = (nicePairs + countMap[revDiff]) % MOD;
      countMap[revDiff]++;
    }
    return nicePairs;
  }

private:
  int reverseNumber(int num)
  {
    int revNum = 0;
    while (num > 0)
    {
      revNum = revNum * 10 + num % 10;
      num /= 10;
    }
    return revNum;
  }
};
/*
- Time complexity : O(NlogN)
- Space complexity : O(N)
*/