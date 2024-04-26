/**
 * @file 605.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-26
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/can-place-flowers/description/
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution
{
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n)
  {
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
      {
        flowerbed[i] = 1;
        count++;
      }
    }
    return count >= n;
  }
};