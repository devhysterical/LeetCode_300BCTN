/*
https://leetcode.com/problems/binary-tree-inorder-traversal/description/

1. Khởi tạo một stack rỗng và một con trỏ curr trỏ tới root.
2. Đẩy tất cả các node bên trái của node hiện tại vào stack và di chuyển con trỏ curr tới node bên trái tiếp theo.
3. Khi con trỏ curr trỏ tới nullptr và stack không rỗng, lấy node trên cùng của stack ra và đẩy giá trị của nó vào result.
4. Lặp lại bước 2 và 3 cho tới khi con trỏ curr trỏ tới nullptr và stack rỗng.

- Time Complexity: O(n)
- Space Complexity: O(n)
*/
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> result;
    stack<TreeNode *> stk;
    TreeNode *curr = root;

    while (curr != nullptr || !stk.empty())
    {
      while (curr != nullptr)
      {
        stk.push(curr);
        curr = curr->left;
      }
      curr = stk.top();
      stk.pop();
      result.push_back(curr->val);
      curr = curr->right;
    }
    return result;
  }
};