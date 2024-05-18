/**
 * @file 637.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 * Time Complexity = O(n)
 * Space Complexity = O(n)
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

vector<double> averageOfLevels(TreeNode *root)
{
  vector<double> res;
  if (!root)
    return res;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int n = q.size();
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      sum += node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    res.push_back(sum / n);
  }
  return res;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector<double> res = averageOfLevels(root);
  for (double i : res)
  {
    cout << i << " ";
  }
  return 0;
}