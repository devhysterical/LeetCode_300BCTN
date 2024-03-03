/**
 * @file 383.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/ransom-note/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    vector<int> counts(26, 0);
    for (char c : magazine)
    {
      counts[c - 'a']++;
    }
    for (char c : ransomNote)
    {
      if (--counts[c - 'a'] < 0)
      {
        return false;
      }
    }
    return true;
  }
};