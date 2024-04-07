/**
 * @file 589.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-07
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
  vector<int> preorder(Node *root)
  {
    vector<int> res;
    if (root == NULL)
      return res;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
      Node *temp = s.top();
      s.pop();
      res.push_back(temp->val);
      for (int i = temp->children.size() - 1; i >= 0; i--)
      {
        s.push(temp->children[i]);
      }
    }
    return res;
  }
};