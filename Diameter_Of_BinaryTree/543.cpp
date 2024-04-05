/**
 * @file 543.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/diameter-of-binary-tree/description/
 * Time complexity = O(n)
 * Space complexity = O(n)
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
  int diameterOfBinaryTree(TreeNode *root)
  {
    int diameter = 0;
    depth(root, diameter);
    return diameter;
  }

private:
  int depth(TreeNode *root, int &diameter)
  {
    if (root == nullptr)
    {
      return 0;
    }
    int left = depth(root->left, diameter);
    int right = depth(root->right, diameter);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
  }
};