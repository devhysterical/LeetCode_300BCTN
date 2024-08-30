/**
 * @file 2699.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-30
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/modify-graph-edge-weights/?envType=daily-question&envId=2024-08-30
 * Time Complexity O(E * log(V))
 * Space Complexity O(V + E)
 */

#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
  {
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<int>> negativeEdges;

    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0], v = edges[i][1], w = edges[i][2];
      if (w == -1)
      {
        negativeEdges.push_back({u, v, i});
      }
      else
      {
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
      }
    }
    vector<long long> dist1 = dijkstra(graph, source, n);

    if (dist1[destination] < target)
    {
      return {};
    }

    if (dist1[destination] == target)
    {
      for (auto &edge : edges)
      {
        if (edge[2] == -1)
          edge[2] = 1e9;
      }
      return edges;
    }

    for (auto &negEdge : negativeEdges)
    {
      int u = negEdge[0], v = negEdge[1], i = negEdge[2];

      graph[u].emplace_back(v, 1);
      graph[v].emplace_back(u, 1);

      vector<long long> dist2 = dijkstra(graph, source, n);
      if (dist2[destination] <= target)
      {
        edges[i][2] = target - dist2[destination] + 1;

        for (int j = i + 1; j < edges.size(); j++)
        {
          if (edges[j][2] == -1)
            edges[j][2] = 1e9;
        }

        return edges;
      }

      edges[i][2] = 1;
    }

    return {};
  }

private:
  vector<long long> dijkstra(const vector<vector<pair<int, int>>> &graph, int start, int n)
  {
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
      auto [d, u] = pq.top();
      pq.pop();

      if (d > dist[u])
        continue;

      for (auto [v, w] : graph[u])
      {
        if (dist[u] + w < dist[v])
        {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }

    return dist;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 5}, {1, 2, 1}};
  int n = 3, source = 0, destination = 2, target = 6;
  vector<vector<int>> result = sol.modifiedGraphEdges(n, edges, source, destination, target);
  for (auto &edge : result)
  {
    cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
  }
}
