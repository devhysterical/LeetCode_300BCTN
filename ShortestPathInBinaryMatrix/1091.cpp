// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    if (grid[0][0] == 1 || grid.back().back() == 1)
    {
      return -1;
    }
    int n = grid.size();
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;
    while (!q.empty())
    {
      auto [x, y] = q.front();
      q.pop();
      if (x == n - 1 && y == n - 1)
      {
        return grid[x][y];
      }
      for (auto [dx, dy] : directions)
      {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0)
        {
          q.push({nx, ny});
          grid[nx][ny] = grid[x][y] + 1;
        }
      }
    }
    return -1;
  }
};

/*
- Time Complexity: O(N^2)
- Space Complexity: O(N^2)
*/