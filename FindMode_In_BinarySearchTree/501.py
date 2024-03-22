# link: https://leetcode.com/problems/find-mode-in-binary-search-tree/description/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        self.prev = None
        self.max_count = 0
        self.current_count = 0
        self.modes = []
        self.inorder(root)
        return self.modes

    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        if self.prev is not None and root.val == self.prev:
            self.current_count += 1
        else:
            self.current_count = 1
        if self.current_count > self.max_count:
            self.max_count = self.current_count
            self.modes = [root.val]
        elif self.current_count == self.max_count:
            self.modes.append(root.val)
        self.prev = root.val
        self.inorder(root.right)


# Time complexity: O(n)
# Space complexity: O(n)
