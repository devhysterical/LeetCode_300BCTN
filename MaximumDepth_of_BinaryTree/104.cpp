/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/

- Time complexity: O(n)
- Space complexity: O(n)
*/
class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
  }
};