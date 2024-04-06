/**
 * @file 563.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/binary-tree-tilt/description/
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
  int findTilt(TreeNode *root)
  {
    int tilt = 0;
    postOrder(root, tilt);
    return tilt;
  }

private:
  int postOrder(TreeNode *root, int &tilt)
  {
    if (root == NULL)
    {
      return 0;
    }
    int leftSum = postOrder(root->left, tilt);
    int rightSum = postOrder(root->right, tilt);
    tilt += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
  }
};