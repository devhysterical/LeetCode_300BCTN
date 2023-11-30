/*
https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2023-11-30

- Time Complexity: O(logn)
- Space Complexity: O(1)
*/
class Solution
{
public:
  int minimumOneBitOperations(int n)
  {
    int result = 0;
    while (n > 0)
    {
      result ^= n;
      n >>= 1;
    }
    return result;
  }
};