/*
https://leetcode.com/problems/linked-list-cycle/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    unordered_set<ListNode *> seenNodes;
    while (head != nullptr)
    {
      if (seenNodes.find(head) != seenNodes.end())
      {
        return true;
      }
      seenNodes.insert(head);
      head = head->next;
    }
    return false;
  }
};