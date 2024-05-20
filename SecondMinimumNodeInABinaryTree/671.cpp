/**
 * @file 671.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
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

int findSecondMinimumValue(TreeNode *root)
{
  if (!root)
  {
    return -1;
  }
  if (!root->left && !root->right)
  {
    return -1;
  }
  int left = root->left->val;
  int right = root->right->val;
  if (left == root->val)
  {
    left = findSecondMinimumValue(root->left);
  }
  if (right == root->val)
  {
    right = findSecondMinimumValue(root->right);
  }
  if (left != -1 && right != -1)
  {
    return min(left, right);
  }
  else if (left != -1)
  {
    return left;
  }
  else
  {
    return right;
  }
}

int main()
{
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  cout << findSecondMinimumValue(root) << endl;
  return 0;
}