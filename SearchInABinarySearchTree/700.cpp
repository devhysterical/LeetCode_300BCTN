/**
 * @file 700.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
  if (!root)
    return nullptr;
  if (root->val == val)
    return root;
  if (root->val > val)
    return searchBST(root->left, val);
  return searchBST(root->right, val);
}

int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  TreeNode *ans = searchBST(root, 2);
  cout << ans->val << endl;
  return 0;
}