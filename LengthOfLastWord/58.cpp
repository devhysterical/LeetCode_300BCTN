// https://leetcode.com/problems/length-of-last-word/

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int length = 0;
    int index = s.size() - 1;
    while (index >= 0 && s[index] == ' ')
      index--;
    while (index >= 0 && s[index] != ' ')
    {
      length++;
      index--;
    }
    return length;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
*/