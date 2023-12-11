/*
https://leetcode.com/problems/excel-sheet-column-number/

- Time Complexity: O(N)
- Space Complexity: O(1)
*/

class Solution
{
public:
  int titleToNumber(string columnTitle)
  {
    int result = 0;

    for (char c : columnTitle)
    {
      int digit = c - 'A' + 1;
      result = result * 26 + digit;
    }
    return result;
  }
};