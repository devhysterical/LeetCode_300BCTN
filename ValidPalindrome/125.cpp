/*
https://leetcode.com/problems/valid-palindrome/description/

- Time complexity: O(n)
- Space complexity: O(n)
*/
class Solution
{
public:
  bool isPalindrome(string s)
  {
    string cleanedString;
    for (char c : s)
    {
      if (isalnum(c))
      {
        cleanedString += tolower(c);
      }
    }
    return cleanedString == string(cleanedString.rbegin(), cleanedString.rend());
  }
};
