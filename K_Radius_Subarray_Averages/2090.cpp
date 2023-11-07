/*
https://leetcode.com/problems/k-radius-subarray-averages/?envType=daily-question&envId=2023-11-07
*/
class Solution
{
public:
  vector<int> getAverages(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<long long> pre(n, 0);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      pre[i] = nums[i] + pre[i - 1];
      cout << pre[i] << " ";
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (i - k < 0 || i + k > n - 1)
      {
        ans.push_back(-1);
      }
      else
      {
        long long no = 2 * k + 1;
        long long presum = pre[i + k];
        if (i - k - 1 >= 0)
        {
          presum -= pre[i - k - 1];
        }
        ans.push_back(presum / no);
      }
    }
    return ans;
  }
};
