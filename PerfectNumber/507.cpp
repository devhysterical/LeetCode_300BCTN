/**
 * @file 507.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/perfect-number/description/
 * Time complexity = O(sqrt(n))
 * Space complexity = O(1)
 */

class Solution
{
public:
  bool checkPerfectNumber(int num)
  {
    if (num == 1)
    {
      return false;
    }
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++)
    {
      if (num % i == 0)
      {
        sum += i;
        if (i != num / i)
        {
          sum += num / i;
        }
      }
    }
    return sum == num;
  }
};