/*
https://leetcode.com/problems/isomorphic-strings/description/

- Time complexity: O(n)
- Space complexity: O(n)
*/

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;

    for (int i = 0; i < s.length(); i++)
    {
      char S = s[i];
      char T = t[i];

      if (s2t.find(S) != s2t.end())
      {
        if (s2t[S] != T)
        {
          return false;
        }
      }
      else
      {
        s2t[S] = T;
      }
      if (t2s.find(T) != t2s.end())
      {
        if (t2s[T] != S)
        {
          return false;
        }
      }
      else
      {
        t2s[T] = S;
      }
    }
    return true;
  }
};