// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution
{
public:
  /**
   * The function calculates the minimum cost of cutting a rod of length n at specified positions given
   * in the vector cuts.
   * 
   * @param n The length of the rod that needs to be cut.
   * @param cuts A vector of integers representing the positions of cuts on a rod of length n. The cuts
   * divide the rod into smaller pieces, and the cost of cutting the rod at a particular position is
   * proportional to the length of the piece being cut. The function is trying to find the minimum cost
   * of cutting the rod
   * 
   * @return The function `minCost` is returning the result of the `dp` function, which is the minimum
   * cost to cut a rod of length `n` at the given positions in the `cuts` vector.
   */
  int minCost(int n, vector<int> &cuts)
  {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<int>> memo(m, vector<int>(m, -1));
    return dp(cuts, memo, 0, m - 1);
  }
  /**
   * The function uses dynamic programming to calculate the minimum cost of cutting a rod into pieces
   * at specified positions.
   * 
   * @param cuts a vector of integers representing the positions of the cuts on a rod
   * @param memo A 2D vector used for memoization, where memo[i][j] stores the minimum cost of cutting
   * the rod between cuts[i] and cuts[j].
   * @param left The index of the leftmost cut in the current subproblem.
   * @param right The index of the rightmost cut in the current subproblem.
   * 
   * @return The function `dp` returns an integer value which represents the minimum cost required to
   * cut the given rod into pieces as per the given cuts.
   */
  int dp(vector<int> &cuts, vector<vector<int>> &memo, int left, int right)
  {
    if (left + 1 == right)
    {
      return 0;
    }
    if (memo[left][right] != -1)
    {
      return memo[left][right];
    }
    int minCost = INT_MAX;
    for (int i = left + 1; i < right; i++)
    {
      int cost = cuts[right] - cuts[left];
      int leftCost = dp(cuts, memo, left, i);
      int rightCost = dp(cuts, memo, i, right);
      minCost = min(minCost, cost + leftCost + rightCost);
    }
    memo[left][right] = minCost;
    return minCost;
  }
};

/*
- Time complexity: O(n^3)
- Space complexity: O(n^2)
===========================
** Problem explanation and problem solving method **
- Problem explanation:
+ Given a rod of length n, and a vector of integers representing the positions of cuts on the rod. The cuts divide the rod into smaller pieces, and the cost of cutting the rod at a particular position is proportional to the length of the piece being cut. The function is trying to find the minimum cost of cutting the rod.
- Problem solving method:
+ We will use dynamic programming to solve this problem.
+ We will create a vector of integers representing the positions of cuts on the rod.
+ We will sort the vector of cuts in ascending order.
+ We will create a 2D vector of integers to store the minimum cost of cutting the rod between cuts[i]
and cuts[j].
+ We will use the `dp` function to calculate the minimum cost of cutting the rod into pieces at
specified positions.
+ We will return the result of the `dp` function, which is the minimum cost to cut a rod of length `n`
at the given positions in the `cuts` vector.
+ We will use the `dp` function to calculate the minimum cost of cutting the rod into pieces at
specified positions.
+ We will return the result of the `dp` function, which is the minimum cost to cut a rod of length `n`
at the given positions in the `cuts` vector.
============================
*/