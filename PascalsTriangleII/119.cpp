/*
https://leetcode.com/problems/pascals-triangle-ii/description/
*/
class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    if (rowIndex == 0)
    {
      return {1};
    }
    vector<int> prevRow = getRow(rowIndex - 1);

    vector<int> row;
    row.push_back(1);

    for (int i = 1; i < rowIndex; ++i)
    {
      row.push_back(prevRow[i - 1] + prevRow[i]);
    }
    row.push_back(1);

    return row;
  }
};
/*
- Time complexity : O(N^2)
- Space complexity : O(N^2)
*/