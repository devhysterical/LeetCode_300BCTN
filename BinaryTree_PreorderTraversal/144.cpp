/*
https://leetcode.com/problems/binary-tree-preorder-traversal/description/

- Time complexity: O(n)
- Space complexity: O(n)
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
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    stack<TreeNode *> st;
    if (root == nullptr)
      return ans;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *node = st.top();
      st.pop();
      ans.push_back(node->val);
      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return ans;
  }
};