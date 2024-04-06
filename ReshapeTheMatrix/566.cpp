/**
 * @file 566.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/reshape-the-matrix/description/
 * Time Complexity: O(m*n)
 * Space Complexity: O(r*c)
 */

class Solution
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
  {
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c)
    {
      return mat;
    }
    vector<vector<int>> res(r, vector<int>(c));
    for (int i = 0; i < r * c; i++)
    {
      res[i / c][i % c] = mat[i / n][i % n];
    }
    return res;
  }
};