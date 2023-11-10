/*
https://leetcode.com/problems/add-digits/

- Time complexity: O(1)
- Space complexity: O(1)
*/
class Solution
{
public:
  int addDigits(int num)
  {
    // Special case for 0
    if (num == 0)
    {
      return 0;
    }
    // Calculate the digital root
    int res = num % 9;
    // Handle the case when the result is 0 (num is divisible by 9)
    return (res == 0) ? 9 : res;
  }
};

/*
- Another solution better than the above one:
class Solution
{
public:
  int addDigits(int num)
  {
    return 1 + (num - 1) % 9;
  }
};
*/