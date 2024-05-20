/**
 * @file 657.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/robot-return-to-origin/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

bool judgeCircle(string moves)
{
  int x = 0, y = 0;
  for (char move : moves)
  {
    if (move == 'U')
    {
      y++;
    }
    else if (move == 'D')
    {
      y--;
    }
    else if (move == 'L')
    {
      x--;
    }
    else if (move == 'R')
    {
      x++;
    }
  }
  return x == 0 && y == 0;
}

int main()
{
  string moves = "LL";
  cout << judgeCircle(moves) << endl;
  return 0;
}