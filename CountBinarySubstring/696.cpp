/**
 * @file 696.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-31
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/count-binary-substrings/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s)
{
  int n = s.size();
  int ans = 0;
  int prev = 0, curr = 1;
  for (int i = 1; i < n; i++)
  {
    if (s[i] == s[i - 1])
    {
      curr++;
    }
    else
    {
      ans += min(prev, curr);
      prev = curr;
      curr = 1;
    }
  }
  ans += min(prev, curr);
  return ans;
}

int main()
{
  string s = "00110011";
  cout << countBinarySubstrings(s) << endl;
  return 0;
}