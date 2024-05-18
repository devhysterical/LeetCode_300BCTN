/**
 * @file 979.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18
 * Time complexity = O(n)
 * Space complexity = O(n)
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int &moves)
{
  if (!root)
    return 0;
  int left = dfs(root->left, moves);
  int right = dfs(root->right, moves);
  moves += abs(left) + abs(right);
  return root->val + left + right - 1;
}

int distributeCoins(TreeNode *root)
{
  int moves = 0;
  dfs(root, moves);
  return moves;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(0);
  root->right = new TreeNode(0);
  cout << distribution(root) << endl;
  return 0;
}