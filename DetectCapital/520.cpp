/**
 * @file 520.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/detect-capital/
 * Time complexity = O(n)
 * Space complexity = O(1)
 */

class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    int n = word.size();
    if (n == 1)
    {
      return true;
    }
    if (islower(word[0]))
    {
      for (int i = 1; i < n; i++)
      {
        if (isupper(word[i]))
        {
          return false;
        }
      }
    }
    else
    {
      if (islower(word[1]))
      {
        for (int i = 2; i < n; i++)
        {
          if (isupper(word[i]))
          {
            return false;
          }
        }
      }
      else
      {
        for (int i = 2; i < n; i++)
        {
          if (islower(word[i]))
          {
            return false;
          }
        }
      }
    }
    return true;
  }
};