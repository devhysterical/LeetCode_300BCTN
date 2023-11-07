/*
https://leetcode.com/problems/same-tree/description/

1. Nếu cả 2 cây đều là nullptr thì trả về true.
2. Nếu chỉ một trong 2 cây là nullptr thì trả về false.
3. Nếu giá trị của các node hiện tại không giống nhau, thì trả về false.
4. Dùng đệ quy để kiểm tra cây con trái và cây con phải. Nếu giống nhau thì trả về true, ngược lại thì trả về false.

- Time complexity: O(n)
- Space complexity: O(n)
*/
class Solution
{
public:
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == nullptr && q == nullptr)
    {
      return true;
    }
    if (p == nullptr || q == nullptr)
    {
      return false;
    }
    if (p->val != q->val)
    {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};