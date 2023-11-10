/*
https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/?envType=daily-question&envId=2023-11-10
*/
class Solution
{
public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
  {
    unordered_map<int, vector<int>> graph;

    // Build the graph
    for (const auto &pair : adjacentPairs)
    {
      graph[pair[0]].push_back(pair[1]);
      graph[pair[1]].push_back(pair[0]);
    }
    // Find the start node (a node with only adjacent node)
    int startNode = 0;
    for (const auto &entry : graph)
    {
      if (entry.second.size() == 1)
      {
        startNode = entry.first;
        break;
      }
    }
    // Traverse the graph to reconstruct the array
    vector<int> result;
    unordered_set<int> visited;
    dfs(graph, startNode, visited, result);

    return result;
  }

  void dfs(const unordered_map<int, vector<int>> &graph, int node, unordered_set<int> &visited, vector<int> &result)
  {
    visited.insert(node);
    result.push_back(node);
    for (int neighbor : graph.at(node))
    {
      if (visited.find(neighbor) == visited.end())
      {
        dfs(graph, neighbor, visited, result);
      }
    }
  }
};