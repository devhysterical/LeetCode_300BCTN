// https://leetcode.com/problems/detonate-the-maximum-bombs/

class Solution
{
public:
  int maximumDetonation(vector<vector<int>> &bombs)
  {
    unordered_map<int, vector<int>> graph;
    int n = bombs.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
        {
          continue;
        }
        int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
        int xj = bombs[j][0], yj = bombs[j][1];
        if ((long long)ri * ri >= (long long)(xi - xj) * (xi - xj) + (long long)(yi - yj) * (yi - yj))
        {
          graph[i].push_back(j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      unordered_set<int> visited;
      int count = dfs(i, visited, graph);
      ans = max(ans, count);
    }
    return ans;
  }

private:
  int dfs(int cur, unordered_set<int> &visited, unordered_map<int, vector<int>> &graph)
  {
    visited.insert(cur);
    int count = 1;
    for (int n : graph[cur])
    {
      if (visited.find(n) == visited.end())
      {
        count += dfs(n, visited, graph);
      }
    }
    return count;
  }
};

/*
- Time complexity: O(n^2)
- Space complexity: O(n^2)
*/