// https://leetcode.com/problems/number-complement/

class Solution
{
public:
  int findComplement(int num)
  {
    if (num == 0)
      return 1;
    unsigned int mask = ~0;
    while (num & mask)
    {
      mask <<= 1;
    }
    return ~num & ~mask;
  }
};

/*
- Time complexity: O(1)
- Space complexity: O(1)
*/