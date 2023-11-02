// https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution
{
public:
  int equalPairs(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i] == getGridColumn(grid, j))
          count++;
      }
    }
    return count;
  }
private:
  vector<int> getGridColumn(vector<vector<int>> &grid, int col)
  {
    int n = grid.size();
    vector<int> column(n);
    for (int i = 0; i < n; i++)
    {
      column[i] = grid[i][col];
    }
    return column;
  }
};

/*
- Time complexity: O(n^3)
- Space complexity: O(n)
*/