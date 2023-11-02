// https://leetcode.com/problems/sqrtx/

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x <= 1)
    {
      return x;
    }
    int left = 0;
    int right = x;
    int result;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (mid <= x / mid)
      {
        result = mid;
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return result;
  }
};

/*
- Time complexity: O(log(n))
- Space complexity: O(1)
*/