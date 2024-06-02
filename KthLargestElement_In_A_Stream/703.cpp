/**
 * @file 703.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 * Time Complexity: O(nlog(k))
 * Space Complexity: O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
  KthLargest(int k, vector<int> &nums)
  {
    this->k = k;
    for (int num : nums)
    {
      pq.push(num);
      if (pq.size() > k)
      {
        pq.pop();
      }
    }
  }

  int add(int val)
  {
    pq.push(val);
    if (pq.size() > k)
    {
      pq.pop();
    }
    return pq.top();
  }

private:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;
};

int main()
{
  vector<int> nums = {4, 5, 8, 2};
  KthLargest kthLargest(3, nums);
  cout << kthLargest.add(3) << endl;  // return 4
  cout << kthLargest.add(5) << endl;  // return 5
  cout << kthLargest.add(10) << endl; // return 5
  cout << kthLargest.add(9) << endl;  // return 8
  cout << kthLargest.add(4) << endl;  // return 8
  return 0;
}
