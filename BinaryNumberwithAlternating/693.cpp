/**
 * @file 693.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-31
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n)
{
  long long x = n ^ (n >> 1);
  return (x & (x + 1)) == 0;
}

int main()
{
  long long n = 5;
  cout << hasAlternatingBits(n) << endl;
  return 0;
}