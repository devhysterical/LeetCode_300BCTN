/*
https://leetcode.com/problems/reverse-bits/

- Time complexity: O(1)
- Space complexity: O(1)
*/

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t reversed = 0;

    for (int i = 0; i < 32; ++i)
    {
      reversed = (reversed << 1) | (n & 1);
      n >>= 1;
    }
    return reversed;
  }
};