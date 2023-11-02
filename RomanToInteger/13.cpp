// https://leetcode.com/problems/roman-to-integer/

class Solution
{
public:
  int romanToInt(string s)
  {
    unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
      if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]])
      {
        res -= romanValues[s[i]];
      }
      else
      {
        res += romanValues[s[i]];
      }
    }
    return res;
  }
};
/*
- Time complexity: O(n)
- Space complexity: O(1)
*/