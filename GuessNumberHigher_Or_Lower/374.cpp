/**
 * @file 374.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-03
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/guess-number-higher-or-lower/description/
 * Time complexity: O(logn)
 * Space complexity: O(1)
 */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
  int guessNumber(int n)
  {
    int left = 1, right = n;
    while (left <= right)
    {
      int middle = left + (right - left) / 2;
      int res = guess(middle);
      if (res == 0)
      {
        return middle;
      }
      else if (res < 0)
      {
        right = middle - 1;
      }
      else
      {
        left = middle + 1;
      }
    }
    return -1;
  }
};