// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int maxLV = 1;
    int maxSum = root->val;
    std::queue<TreeNode *> q;
    q.push(root);
    int lv = 1;
    while (!q.empty())
    {
      int lvSize = q.size();
      int lvSum = 0;
      for (int i = 0; i < lvSize; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        lvSum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      if (lvSum > maxSum)
      {
        maxSum = lvSum;
        maxLV = lv;
      }
      lv++;
    }
    return maxLV;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(n)
*/