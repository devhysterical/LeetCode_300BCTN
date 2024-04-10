/**
 * @file 950.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 */

class Solution
{
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck)
  {
    sort(deck.begin(), deck.end());
    deque<int> dq;
    dq.push_back(deck.back());
    for (int i = deck.size() - 2; i >= 0; i--)
    {
      dq.push_front(dq.back());
      dq.pop_back();
      dq.push_front(deck[i]);
    }
    return vector<int>(dq.begin(), dq.end());
  }
};