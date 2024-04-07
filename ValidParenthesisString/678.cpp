/**
 * @file 678.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-07
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  bool checkValidString(string s)
  {
    int n = s.size();
    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        low++;
        high++;
      }
      else if (s[i] == ')')
      {
        low--;
        high--;
      }
      else
      {
        low--;
        high++;
      }
      if (high < 0)
        return false;
      if (low < 0)
        low = 0;
    }
    return low == 0;
  }
};