/*
https://leetcode.com/problems/balanced-binary-tree/description/

1. The isBalanced function is the main entry point, which takes the root of the binary tree.
2. It calls the checkHeight function to recursively check if the tree is balanced. If the checkHeight function returns -1, it means the tree is unbalanced and isBalanced returns false. Otherwise, it returns true.
3. The checkHeight function checks the height and balance of the tree starting from the given node.
4. If the node is nullptr, it returns 0 (the height of an empty tree).
5. It recursively checks the left subtree and stores its height in leftHeight. If the left subtree is unbalanced, it returns -1.
6. It recursively checks the right subtree and stores its height in rightHeight. If the right subtree is unbalanced, it returns -1.
7. It checks the balance at the current node by comparing the absolute difference between leftHeight and rightHeight with 1. If it's greater than 1, it means the current node is unbalanced, and it returns -1.
8. If the current node is balanced, it returns the height of the current node as 1 + max(leftHeight, rightHeight).

- Time complexity: O(N)
- Space complexity: O(H)
  + H is the height of the tree.
  + The space complexity is O(H) because we need to store the height of each node in the call stack.
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
  bool isBalanced(TreeNode *root)
  {
    if (checkHeight(root) == -1)
    {
      return false; // If the tree is unbalanced, return false.
    }
    return true; // If the tree is balanced, return true.
  }

  // Helper function to check the height and balance of the tree.
  int checkHeight(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0; // The height of an empty tree is 0.
    }

    // Recursively check the left subtree.
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
    {
      return -1; // Left subtree is unbalanced.
    }

    // Recursively check the right subtree.
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
    {
      return -1; // Right subtree is unbalanced.
    }

    // Check the balance at the current node.
    if (abs(leftHeight - rightHeight) > 1)
    {
      return -1; // Current node is unbalanced.
    }

    // Return the height of the current node.
    return 1 + max(leftHeight, rightHeight);
  }
};
