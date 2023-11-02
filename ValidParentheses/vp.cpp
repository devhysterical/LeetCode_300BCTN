/*
https://leetcode.com/problems/valid-parentheses/
*/

class Solution
{
public:
  /**
   * The function checks if a given string of parentheses, curly braces, and square brackets is valid
   * or not using a stack data structure.
   * 
   * @param s a string containing parentheses, curly braces, and square brackets. The function checks
   * if the string has a valid combination of opening and closing brackets.
   * 
   * @return a boolean value indicating whether the input string `s` contains valid parentheses, curly
   * braces, and square brackets. If the string is valid, the function returns `true`, otherwise it
   * returns `false`.
   */
  bool isValid(string s)
  {
    stack<char> stack;
    for (char c : s)
    {
      if (c == '(' || c == '{' || c == '[')
      {
        stack.push(c);
      }
      else if (c == ')' && !stack.empty() && stack.top() == '(')
      {
        stack.pop();
      }
      else if (c == '}' && !stack.empty() && stack.top() == '{')
      {
        stack.pop();
      }
      else if (c == ']' && !stack.empty() && stack.top() == '[')
      {
        stack.pop();
      }
      else
      {
        return false;
      }
    }
    return stack.empty();
  }
};

/*
#Intuition:
- If the string is valid, it must have an even number of characters.
- If the string is valid, the number of opening brackets must be equal to the number of closing brackets.
#Approach:
- We use a stack to store the opening brackets.
- If we encounter a closing bracket, we check if the top of the stack is the corresponding opening bracket.
- If the stack is empty, or the top of the stack is not the corresponding opening bracket, we return false.
- If we reach the end of the string and the stack is not empty, we return false.
- Otherwise, we return true.
#Time Complexity:
- O(n)
#Space Complexity:
- O(n)
*/