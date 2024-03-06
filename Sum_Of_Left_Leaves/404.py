# link: https://leetcode.com/problems/sum-of-left-leaves/description/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        """
        Calculate the sum of values of left leaves in a binary tree.

        Given the root of a binary tree, this function calculates the sum of values of left leaves
        in the tree. A left leave is a leaf node that is the left child of its parent.

        Args:
        - root (Optional[TreeNode]): The root of the binary tree.

        Returns:
        - int: The sum of values of left leaves in the binary tree.
        """

        def dfs(node: TreeNode, isLeft: bool) -> int:
            """
            Depth-first search (DFS) function to traverse the binary tree and calculate the sum.

            Args:
            - node (TreeNode): The current node in the binary tree.
            - isLeft (bool): Indicates whether the current node is the left child of its parent.

            Returns:
            - int: The sum of values of left leaves in the subtree rooted at the current node.
            """
            if not node:
                return 0
            if not node.left and not node.right:
                return node.val if isLeft else 0
            return dfs(node.left, True) + dfs(node.right, False)

        return dfs(root, False)


# Time complexity: O(n)
# Space complexity: O(n)
