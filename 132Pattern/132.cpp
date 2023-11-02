class Solution
{
public:
  bool find132pattern(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 3)
    {
      return false;
    }

    vector<int> minPrefix(n);
    minPrefix[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
      minPrefix[i] = min(minPrefix[i - 1], nums[i]);
    }

    stack<int> candidate2;

    for (int j = n - 1; j >= 0; j--)
    {
      if (nums[j] > minPrefix[j])
      {
        while (!candidate2.empty() && candidate2.top() <= minPrefix[j])
        {
          candidate2.pop();
        }
        if (!candidate2.empty() && candidate2.top() < nums[j])
        {
          return true;
        }
        candidate2.push(nums[j]);
      }
    }
    return false;
  }
};