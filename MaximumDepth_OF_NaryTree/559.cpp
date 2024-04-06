/**
 * @file 559.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-06
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
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
  int maxDepth(Node *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    int depth = 0;
    for (auto child : root->children)
    {
      depth = max(depth, maxDepth(child));
    }
    return depth + 1;
  }
};