/**
 * @file 617.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-18
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/merge-two-binary-trees/description/
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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
  if (!root1)
    return root2;
  if (!root2)
    return root1;
  root1->val += root2->val;
  root1->left = mergeTrees(root1->left, root2->left);
  root1->right = mergeTrees(root1->right, root2->right);
  return root1;
}

int main()
{
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(3);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(5);

  TreeNode *root2 = new TreeNode(2);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(3);
  root2->left->right = new TreeNode(4);
  root2->right->right = new TreeNode(7);

  TreeNode *root = mergeTrees(root1, root2);
  return 0;
}