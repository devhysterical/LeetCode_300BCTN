/**
 * @file 345.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/reverse-vowels-of-a-string/
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

class Solution
{
public:
  string reverseVowels(string s)
  {
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
      if (isVowel(s[left]) && isVowel(s[right]))
      {
        swap(s[left++], s[right--]);
      }
      else if (isVowel(s[left]))
      {
        right--;
      }
      else
      {
        left++;
      }
    }
    return s;
  }

private:
  bool isVowel(char c)
  {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};