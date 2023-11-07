/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

1. Initialize a pointer `current` to the head of the linked list.
2. While `current` and `current->next` are not `nullptr`, check if the value of the current node is the same as the value of the next node.
3. If they are the same, delete the next node by changing the `next` pointer of the current node to skip the next node.
4. If they are not the same, move `current` to the next node.
5. Return the head of the linked list.

- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *current = head;
    while (current != nullptr && current->next != nullptr)
    {
      if (current->next->val == current->val)
      {
        ListNode *temp = current->next;
        current->next = current->next->next;
        delete temp;
      }
      else
      {
        current = current->next;
      }
    }
    return head;
  }
};