// https://leetcode.com/problems/plus-one/

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
      if (digits[i] < 9)
      {
        digits[i]++;
        return digits;
      }
      else
      {
        digits[i] = 0;
      }
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
*/