/*
https://leetcode.com/problems/excel-sheet-column-title/description/

- Time Complexity: O(logn)
- Space Complexity: O(1)
*/
class Solution
{
public:
  string convertToTitle(int columnNumber)
  {
    string result = "";
    while (columnNumber > 0)
    {
      int remainder = (columnNumber % 26 == 0) ? 26 : columnNumber % 26;
      result += 'A' + remainder - 1;
      columnNumber = (columnNumber - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};