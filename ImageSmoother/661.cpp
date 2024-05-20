/**
 * @file 661.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/image-smoother/description/
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
  int m = img.size();
  int n = img[0].size();
  vector<vector<int>> res(m, vector<int>(n, 0));
  vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}};

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int sum = 0;
      int count = 0;

      for (auto dir : dirs)
      {
        int x = i + dir[0];
        int y = j + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n)
        {
          sum += img[x][y];
          count++;
        }
      }
      res[i][j] = sum / count;
    }
  }
  return res;
}

int main()
{
  vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
  vector<vector<int>> res = imageSmoother(img);

  for (auto row : res)
  {
    for (int col : row)
    {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
