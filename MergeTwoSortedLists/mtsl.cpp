/*
https://leetcode.com/problems/merge-two-sorted-lists/
*/

class Solution
{
public:
  /**
   * The function merges two linked lists in ascending order and returns the merged list.
   * 
   * @param l1 A pointer to the head of the first linked list.
   * @param l2 The parameter `l2` is a pointer to the head of a linked list.
   * 
   * @return a ListNode pointer, which is the head of the merged linked list.
   */
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        cur->next = l1;
        l1 = l1->next;
      }
      else
      {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1)
    {
      cur->next = l1;
    }
    else
    {
      cur->next = l2;
    }
    return dummy->next;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
===========================
** Problem explanation and problem solving method **
- Problem explanation:
+ Given two sorted linked lists, merge them into a single sorted linked list.
- Problem solving method:
+ We will use the greedy algorithm to solve this problem.
+ We will create a dummy node and a pointer to the dummy node.
+ We will iterate through the two linked lists and compare the values of the nodes.
+ We will add the node with the smaller value to the merged linked list.
+ We will return the merged linked list.
============================
*/