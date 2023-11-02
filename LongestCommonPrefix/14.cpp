// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
  /**
   * The function finds the longest common prefix among a vector of strings.
   * 
   * @param strs A reference to a vector of strings, which represents the input strings for finding the
   * longest common prefix.
   * 
   * @return a string which is the longest common prefix among the strings in the input vector `strs`.
   * If the input vector is empty, an empty string is returned.
   */
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.empty())
    {
      return "";
    }
    int prefixLength = 0;
    while (true)
    {
      if (prefixLength >= strs[0].length())
      {
        return strs[0].substr(0, prefixLength);
      }
      char currentChar = strs[0][prefixLength];
      for (int i = 1; i < strs.size(); i++)
      {
        if (prefixLength >= strs[i].length() || strs[i][prefixLength] != currentChar)
        {
          return strs[0].substr(0, prefixLength);
        }
      }
      prefixLength++;
    }
  }
};

/*
- Time complexity: O(n * m)
- Space complexity: O(1)
===========================
** Problem explanation and problem solving method **
- Problem explanation:
+ Given a vector of strings, find the longest common prefix among them.
+ If there is no common prefix, return an empty string "".
- Problem solving method:
+ We will use the greedy algorithm to solve this problem.
+ We will iterate through the first string in the vector and compare each character with the corresponding character in the other strings.
+ If the characters are the same, we will increase the length of the prefix by 1.
+ If the characters are different, we will return the prefix.
+ If the length of the prefix is greater than or equal to the length of the first string, we will return the prefix.
+ If the vector is empty, we will return an empty string.
============================
*/