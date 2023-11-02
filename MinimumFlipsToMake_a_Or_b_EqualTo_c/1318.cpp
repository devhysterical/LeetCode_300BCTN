// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution
{
public:
  int minFlips(int a, int b, int c)
  {
    int count = 0;
    while (a || b || c)
    {
      int bitA = a & 1;
      int bitB = b & 1;
      int bitC = c & 1;
      if (bitC == 0)
      {
        if (bitA == 1)
        {
          count++;
        }
        if (bitB == 1)
        {
          count++;
        }
      }
      else
      {
        if (bitA == 0 && bitB == 0)
        {
          count++;
        }
      }
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    return count;
  }
};

/*
- Time complexity: O(1)
- Space complexity: O(1)
*/