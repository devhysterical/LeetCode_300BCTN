/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

1. The sortedArrayToBST function is the main entry point, which takes the sorted array nums.
2. It calls the helper function sortedArrayToBSTHelper, passing the array, left, and right indices.
3.In the sortedArrayToBSTHelper function, we check if left is greater than right. If so, there are no elements in this range, so we return nullptr.
4. Calculate the middle index mid to find the middle element in the current range.
5. Create a new tree node with the middle element as the root.
6. Recursively build the left subtree by calling sortedArrayToBSTHelper with the left and mid - 1 indices.
7. Recursively build the right subtree by calling sortedArrayToBSTHelper with the mid + 1 and right indices.
8. Return the root, which represents the height-balanced binary search tree.

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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
  }

  TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int left, int right)
  {
    if (left > right)
    {
      return nullptr;
    }

    // Find the middle element of the current range
    int mid = left + (right - left) / 2;

    // Create a new tree node with the middle element as the root
    TreeNode *root = new TreeNode(nums[mid]);

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return root;
  }
};
