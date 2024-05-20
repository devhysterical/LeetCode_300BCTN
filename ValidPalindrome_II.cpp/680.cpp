/**
 * @file 680.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/valid-palindrome-ii/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r)
{
  while (l < r)
  {
    if (s[l] != s[r])
    {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

bool validPalindrome(string s)
{
  int l = 0, r = s.size() - 1;
  while (l < r)
  {
    if (s[l] != s[r])
    {
      return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
    }
    l++;
    r--;
  }
  return true;
}

int main()
{
  string s = "aba";
  cout << validPalindrome(s) << endl;
  return 0;
}