/**
 * @file 705.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/design-hashset/description/
 * Time Complexity: O(1)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
  MyHashSet()
  {
    data = vector<list<int>>(size);
  }

  void add(int key)
  {
    if (!contains(key))
    {
      data[key % size].push_back(key);
    }
  }

  void remove(int key)
  {
    if (contains(key))
    {
      data[key % size].remove(key);
    }
  }

  bool contains(int key)
  {
    for (int k : data[key % size])
    {
      if (k == key)
      {
        return true;
      }
    }
    return false;
  }

private:
  vector<list<int>> data;
  const int size = 10000;
};

int main()
{
  MyHashSet hashSet;
  hashSet.add(1);
  hashSet.add(2);
  cout << hashSet.contains(1) << endl; // return true
  cout << hashSet.contains(3) << endl; // return false
  hashSet.add(2);
  cout << hashSet.contains(2) << endl; // return true
  hashSet.remove(2);
  cout << hashSet.contains(2) << endl; // return false
  return 0;
}