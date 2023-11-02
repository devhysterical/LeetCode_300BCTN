// https://leetcode.com/problems/make-array-strictly-increasing/

class Solution
{
public:
  int makeArrayIncreasing(std::vector<int> &arr1, std::vector<int> &arr2)
  {
    std::sort(arr2.begin(), arr2.end());
    std::map<std::pair<int, int>, int> dp;
    int answer = dfs(0, -1, arr1, arr2, dp);
    return (answer < 2001) ? answer : -1;
  }
private:
  int dfs(int i, int prev, const std::vector<int> &arr1, const std::vector<int> &arr2, std::map<std::pair<int, int>, int> &dp)
  {
    if (i == arr1.size())
    {
      return 0;
    }
    if (dp.count({i, prev}))
    {
      return dp[{i, prev}];
    }
    int cost = 2001;
    if (arr1[i] > prev)
    {
      cost = dfs(i + 1, arr1[i], arr1, arr2, dp);
    }
    int idx = bisectRight(arr2, prev);
    if (idx < arr2.size())
    {
      cost = std::min(cost, 1 + dfs(i + 1, arr2[idx], arr1, arr2, dp));
    }
    dp[{i, prev}] = cost;
    return cost;
  }
  int bisectRight(const std::vector<int> &arr, int value)
  {
    int left = 0, right = arr.size();
    while (left < right)
    {
      int mid = (left + right) / 2;
      if (arr[mid] <= value)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }
    return left;
  }
};

/*
- Time complexity: O(N^2 * logN)
- Space complexity: O(N^2)
*/
