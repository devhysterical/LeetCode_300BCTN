/**
 * @file 572.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/subtree-of-another-tree/description/
 * Time Complexity: O(n*m)
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
  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    if (root == NULL)
    {
      return false;
    }
    if (isSameTree(root, subRoot))
    {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

private:
  bool isSameTree(TreeNode *root, TreeNode *subRoot)
  {
    if (root == NULL && subRoot == NULL)
    {
      return true;
    }
    if (root == NULL || subRoot == NULL)
    {
      return false;
    }
    if (root->val != subRoot->val)
    {
      return false;
    }
    return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
  }
};