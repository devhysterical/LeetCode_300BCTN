/**
 * @file 653.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
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

bool findTarget(TreeNode *root, int k)
{
  unordered_set<int> s;
  return dfs(root, k, s);
}

bool dfs(TreeNode *root, int k, unordered_set<int> &s)
{
  if (root == NULL)
  {
    return false;
  }
  if (s.count(k - root->val))
  {
    return true;
  }
  s.insert(root->val);
  return dfs(root->left, k, s) || dfs(root->right, k, s);
}

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  int k = 9;
  cout << findTarget(root, k) << endl;
  return 0;
}