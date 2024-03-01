/**
 * @file 344.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/reverse-string/description/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};