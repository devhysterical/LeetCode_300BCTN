/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
  int minDepth(TreeNode *root)
  {
    if (!root)
    {
      return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int depth = 1;

    while (!q.empty())
    {
      int levelSize = q.size();
      for (int i = 0; i < levelSize; ++i)
      {
        TreeNode *node = q.front();
        q.pop();
        // Check if the node is a leaf
        if (!node->left && !node->right)
        {
          return depth;
        }
        // Add child nodes to the queue
        if (node->left)
        {
          q.push(node->left);
        }
        if (node->right)
        {
          q.push(node->right);
        }
      }
      // Move to the next level
      ++depth;
    }
    return depth;
  }
};