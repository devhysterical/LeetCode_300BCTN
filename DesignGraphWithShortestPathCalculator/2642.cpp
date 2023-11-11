/*
https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/?envType=daily-question&envId=2023-11-11

- Time complexity: O(ElogV)
- Space complexity: O(V)
*/
class Graph
{
  int n;
  unordered_map<int, vector<pair<int, int>>> adjList; // Biểu diễn đồ thị bằng danh sách kề (adjacency list - adjList). Mỗi nút ánh xạ tới một vector các cặp, trong đó mỗi cặp đại diện cho một nút liền kề và cost cạnh tương ứng.

public:
  /*
  - Khởi tạo đối tượng với số nút n và danh sách các cạnh.
  - Mỗi cạnh được biểu diễn dưới dạng 1 vector[from, to, cost], biểu thị một canh từ nút from đến nút to với chi phí cost.
  */
  Graph(int n, vector<vector<int>> &edges)
  {
    this->n = n;
    for (auto &edge : edges)
    {
      int from = edge[0];
      int to = edge[1];
      int cost = edge[2];
      adjList[from].push_back({to, cost}); // 
    }
  }
  /*
  - Cho phép thêm các cạnh mới vào đồ thị
  - Lấy một cạnh được biểu diễn dưới dạng 1 vector[from, to, cost] và thêm vào danh sách kề.
  */
  void addEdge(vector<int> edge)
  {
    int from = edge[0];
    int to = edge[1];
    int cost = edge[2];
    adjList[from].push_back({to, cost});
  }
  /*
  - Tìm đường đi ngắn nhất từ node1 và node2 và trả về cost tối thiểu của đường đi từ node1 đến node2.
  - Nếu không có đường đi từ node1 đến node2 thì trả về -1.
  - Sử dụng thuật toán Dijkstra để tìm đường đi ngắn nhất giữa 2 nút node1 và node2. Duy trì hàng đợi ưu tiên (pq) để chọn nút có khoảng cách nhỏ nhất tới node1. Sử dụng một map để lưu khoảng cách từ node1 tới các nút còn lại.
  */
  int shortestPath(int node1, int node2)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> distance;
    // Initialize distances with infinity
    for (int i = 0; i < n; ++i)
    {
      distance[i] = numeric_limits<int>::max();
    }
    distance[node1] = 0;
    pq.push({0, node1});
    /*
    - Vòng lặp chính tiếp tục cho đến khi hàng đợi ưu tiên rỗng.
    - Trong mỗi lần lặp, nút có khoảng cách nhỏ nhất (currNode) sẽ được đưa ra khỏi hàng đợi ưu tiên. Nếu currNode bằng node2 thì trả về khoảng cách tới node2.
    */
    while (!pq.empty())
    {
      int currNode = pq.top().second;
      int currDist = pq.top().first;
      pq.pop();

      if (currNode == node2)
      {
        return currDist;
      }
      /*
      - Đối với mỗi neighbor của currNode, nếu khoảng cách tích lũy để đến được neighbor thông qua currNode nhỏ hơn khoảng cách đã biết thì cập nhật lại khoảng cách và đưa neighbor vào hàng đợi ưu tiên.
      */
      for (const auto &neighbor : adjList[currNode])
      {
        int nextNode = neighbor.first;
        int cost = neighbor.second;

        if (currDist + cost < distance[nextNode])
        {
          distance[nextNode] = currDist + cost;
          pq.push({distance[nextNode], nextNode});
        }
      }
    }
    return -1; // Nếu vòng lặp hoàn thành mà không tìm thấy đường đi từ node1 đến node2 thì trả về -1.
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */