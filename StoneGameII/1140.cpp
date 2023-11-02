// https://leetcode.com/problems/stone-game-ii/

class Solution
{
public:
  int stoneGameII(vector<int> &piles)
  {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> suffixSum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      suffixSum[i] = suffixSum[i + 1] + piles[i];
    }
    auto aliceScore = [&](int i, int M)
    {
      return suffixSum[i] - dp[i + M][max(2 * M, n)] + dp[i + M][max(2 * M, n)];
    };
    for (int i = n - 1; i >= 0; i--)
    {
      for (int M = 1; M <= n; M++)
      {
        if (i + 2 * M >= n)
        {
          dp[i][M] = suffixSum[i];
        }
        else
        {
          for (int X = 1; X <= 2 * M; X++)
          {
            dp[i][M] = max(dp[i][M], aliceScore(i, X));
          }
        }
      }
    }

    return dp[0][1];
  }
};