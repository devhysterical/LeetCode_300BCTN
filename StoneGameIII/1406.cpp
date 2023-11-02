// https://leetcode.com/problems/stone-game-iii/
class Solution
{
public:
  /**
   * The function "stoneGameIII" takes a vector of integers representing stone values and returns the
   * winner of a game played between Alice and Bob.
   * 
   * @param stoneValue A vector of integers representing the values of stones in a game. Each stone has
   * a certain value and the players take turns picking stones until there are no more left. The goal
   * is to maximize the score difference between the two players.
   * 
   * @return a string that represents the winner of the game. If the score difference is greater than
   * 0, "Alice" is returned. If the score difference is less than 0, "Bob" is returned. If the score
   * difference is 0, "Tie" is returned.
   */
  string stoneGameIII(vector<int> &stoneValue)
  {
    int n = stoneValue.size();
    vector<int> dp(n, INT_MIN);
    int scoreDiff = dfs(stoneValue, dp, 0);
    if (scoreDiff > 0)
    {
      return "Alice";
    }
    else if (scoreDiff < 0)
    {
      return "Bob";
    }
    else
    {
      return "Tie";
    }
  }
  /**
   * This is a recursive function that calculates the maximum difference between the sum of a
   * contiguous sub array of up to three elements and the sum of the remaining elements in a given
   * vector, using dynamic programming to avoid redundant calculations.
   * 
   * @param stoneValue a vector of integers representing the values of stones in a game.
   * @param dp A vector representing the memoization table for dynamic programming. It stores the
   * maximum difference in score that can be achieved by the current player starting from the current
   * stone index. If the value of dp[start] is not INT_MIN, it means that the result for this index has
   * already been computed and can be
   * @param start The index of the current stone being considered in the recursion.
   * 
   * @return The function `dfs` returns an integer value, which is the maximum difference between the
   * sum of stones taken by the current player and the sum of stones taken by the other player,
   * assuming optimal play by both players.
   */
  int dfs(vector<int> &stoneValue, vector<int> &dp, int start)
  {
    if (start >= stoneValue.size())
    {
      return 0;
    }
    if (dp[start] != INT_MIN)
    {
      return dp[start];
    }
    int maxDiff = INT_MIN;
    int take = 0;
    for (int i = 0; i < 3 && start + i < stoneValue.size(); i++)
    {
      take += stoneValue[start + i];
      maxDiff = max(maxDiff, take - dfs(stoneValue, dp, start + i + 1));
    }
    dp[start] = maxDiff;
    return maxDiff;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(n)
*/