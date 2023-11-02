// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution
{
public:
  int balancedStringSplit(string s)
  {
    int count = 0;
    int balanceL = 0;
    int balanceR = 0;
    for (char ch : s)
    {
      if (ch == 'L')
      {
        balanceL++;
      }
      else
      {
        balanceR++;
      }
      if (balanceL == balanceR)
      {
        count++;
        balanceL = 0;
        balanceR = 0;
      }
    }
    return count;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
*/