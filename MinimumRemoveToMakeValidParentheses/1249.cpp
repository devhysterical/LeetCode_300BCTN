/**
 * @file 1249.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        st.push(i);
      }
      else if (s[i] == ')')
      {
        if (!st.empty())
        {
          st.pop();
        }
        else
        {
          s[i] = '*';
        }
      }
    }
    while (!st.empty())
    {
      s[st.top()] = '*';
      st.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};