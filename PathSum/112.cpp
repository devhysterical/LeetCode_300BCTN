/*
https://leetcode.com/problems/path-sum/description/
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
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root) {
      return false;
    }
    if (!root -> left && !root -> right) {
      return targetSum - root -> val == 0;
    }
    bool leftResult = hasPathSum(root -> left, targetSum - root -> val);
    bool rightResult = hasPathSum(root -> right, targetSum - root -> val);

    return leftResult || rightResult;
  }
};
/*
- Time complexity : O(N)
- Space complexity : O(N)
*/