// https://leetcode.com/problems/snapshot-array/

class SnapshotArray
{
private:
  int id;
  std::vector<std::vector<std::pair<int, int>>> history_records;
public:
  SnapshotArray(int length)
  {
    id = 0;
    history_records.resize(length, {{0, 0}});
  }
  void set(int index, int val)
  {
    history_records[index].emplace_back(id, val);
  }
  int snap()
  {
    id++;
    return id - 1;
  }
  int get(int index, int snap_id)
  {
    const std::vector<std::pair<int, int>> &snapshot = history_records[index];
    auto it = std::upper_bound(snapshot.begin(), snapshot.end(), std::make_pair(snap_id, 1'000'000'000));
    return std::prev(it)->second;
  }
};

/*
- Time complexity: O(logN)
- Space complexity: O(N)
*/