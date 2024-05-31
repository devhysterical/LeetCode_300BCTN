/**
 * @file 682.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-31
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/baseball-game/description/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string> &operations)
{
  stack<int> st;
  for (int i = 0; i < operations.size(); i++)
  {
    if (operations[i] == "C")
    {
      st.pop();
    }
    else if (operations[i] == "D")
    {
      st.push(2 * st.top());
    }
    else if (operations[i] == "+")
    {
      int x = st.top();
      st.pop();
      int y = st.top();
      st.push(x);
      st.push(x + y);
    }
    else
    {
      st.push(stoi(operations[i]));
    }
  }
  int sum = 0;
  while (!st.empty())
  {
    sum += st.top();
    st.pop();
  }
  return sum;
}

int main()
{
  vector<string> operations = {"5", "2", "C", "D", "+"};
  cout << calPoints(operations) << endl;
  return 0;
}