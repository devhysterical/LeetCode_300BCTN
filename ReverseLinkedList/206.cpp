/**
 * @file 206.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/reverse-linked-list/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// recursive solution
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    ListNode *reversedList = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return reversedList;
  }
};

// // iterative solution
// class Solution
// {
// public:
//   ListNode *reverseList(ListNode *head)
//   {
//     ListNode *prev = nullptr;
//     ListNode *current = head;

//     while (current != nullptr)
//     {
//       ListNode *nextNode = current->next;
//       current->next = prev;
//       prev = current;
//       current = nextNode;
//     }
//     return prev;
//   }
// };
