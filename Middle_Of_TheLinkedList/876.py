# link: https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Find the middle node of a singly-linked list.

        Given the head of a singly-linked list, this function finds and returns the middle node.
        If there are two middle nodes, it returns the second middle node.

        Args:
        - head (Optional[ListNode]): The head of the singly-linked list.

        Returns:
        - Optional[ListNode]: The middle node of the given singly-linked list, or None if the list is empty.
        """
        slow = head
        fast = head

        # Move 'slow' one step at a time and 'fast' two steps at a time
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow
# Time complexity: O(n)
# Space complexity: O(1)