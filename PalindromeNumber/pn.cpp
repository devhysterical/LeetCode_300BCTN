/*
https://leetcode.com/problems/palindrome-number/
*/
class Solution
{
public:
  /**
   * The function checks if a given integer is a palindrome or not.
   * 
   * @param x an integer that we want to check if it is a palindrome or not.
   * 
   * @return a boolean value indicating whether the input integer is a palindrome or not.
   */
  bool isPalindrome(int x)
  {
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
      return false;
    }
    int reversed = 0;
    while (x > reversed)
    {
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }
    return x == reversed || x == reversed / 10;
  }
};

/*
- Time complexity: O(log(x))
- Space complexity: O(1)
===========================
** Problem explanation and problem solving method **
- Problem explanation:
+ Given an integer, check if it is a palindrome.
+ An integer is a palindrome when it reads the same backward as forward.
- Problem solving method:
+ We will use the greedy algorithm to solve this problem. We will use two pointers to iterate through the integer from the left and right sides.
+ We will compare the values of the two pointers. If they are the same, we will move the pointers to the next positions.
+ If they are different, we will return false.
+ If the two pointers meet, we will return true.
============================
*/