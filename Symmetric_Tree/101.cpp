/*
https://leetcode.com/problems/symmetric-tree/description/

- Time complexity: O(n)
- Space complexity: O(n)
*/
class Solution
{
public:
  bool isMirror(TreeNode *t1, TreeNode *t2)
  {
    if (t1 == nullptr && t2 == nullptr)
      return true;
    if (t1 == nullptr || t2 == nullptr)
      return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
  }

  bool isSymmetric(TreeNode *root)
  {
    return isMirror(root, root);
  }
};