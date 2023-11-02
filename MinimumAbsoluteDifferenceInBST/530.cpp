// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};
class Solution
{
public:
  int getMinimumDifference(TreeNode *root)
  {
    int minDiff = INT_MAX;
    int prev = -1;
    inorderTraversal(root, minDiff, prev);
    return minDiff;
  }
private:
  void inorderTraversal(TreeNode *root, int &minDiff, int &prev)
  {
    if (root == nullptr)
      return;
    inorderTraversal(root->left, minDiff, prev);
    if (prev != -1)
      minDiff = min(minDiff, root->val - prev);
    prev = root->val;
    inorderTraversal(root->right, minDiff, prev);
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(n)
*/