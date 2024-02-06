/**
 * @file 232.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/implement-queue-using-stacks/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class MyQueue
{
private:
  stack<int> stack1;
  stack<int> stack2;

public:
  MyQueue()
  {
  }

  void push(int x)
  {
    stack1.push(x);
  }

  int pop()
  {
    if (stack2.empty())
    {
      while (!stack1.empty())
      {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }

    int front = stack2.top();
    stack2.pop();
    return front;
  }

  int peek()
  {
    if (stack2.empty())
    {
      while (!stack1.empty())
      {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    return stack2.top();
  }

  bool empty()
  {
    return stack1.empty() && stack2.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */