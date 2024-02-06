/**
 * @file 234.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/palindrome-linked-list/description/
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
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *secondHalf = reverse(slow);

    while (secondHalf != nullptr)
    {
      if (head->val != secondHalf->val)
      {
        return false;
      }
      head = head->next;
      secondHalf = secondHalf->next;
    }
    return true;
  }

private:
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = nullptr;
    while (head != nullptr)
    {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};