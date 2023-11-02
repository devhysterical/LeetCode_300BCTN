// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution
{
public:
  long long getSum(int index, int value, int n)
  {
    long long count = 0;
    if (value > index)
    {
      count += (value + value - index) * (long long)(index + 1) / 2;
    }
    else
    {
      count += (value + 1) * (long long)value / 2 + index - value + 1;
    }
    if (value >= n - index)
    {
      count += (value + value - n + 1 + index) * (long long)(n - index) / 2;
    }
    else
    {
      count += (value + 1) * (long long)value / 2 + n - index - value;
    }
    return count - value;
  }
  int maxValue(int n, int index, int maxSum)
  {
    int left = 1, right = maxSum;
    while (left < right)
    {
      int mid = (left + right + 1) / 2;
      if (getSum(index, mid, n) <= maxSum)
      {
        left = mid;
      }
      else
      {
        right = mid - 1;
      }
    }
    return left;
  }
};

/*
- Time complexity: O(log(maxSum))
- Space complexity: O(1)
*/
