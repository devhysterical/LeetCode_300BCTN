// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution
{
public:
  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
  {
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
      if (manager[i] != -1)
      {
        graph[manager[i]].push_back(i);
      }
    }
    return dfs(graph, headID, informTime);
  }

private:
  int dfs(const unordered_map<int, vector<int>> &graph, int cur, const vector<int> &informTime)
  {
    int maxTime = 0;
    if (graph.count(cur))
    {
      for (int sub : graph.at(cur))
      {
        maxTime = max(maxTime, dfs(graph, sub, informTime));
      }
    }
    return maxTime + informTime[cur];
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(n)
*/