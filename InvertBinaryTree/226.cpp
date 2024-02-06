/**
 * @file 226.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/invert-binary-tree/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return nullptr;
    }
    TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
  }
};