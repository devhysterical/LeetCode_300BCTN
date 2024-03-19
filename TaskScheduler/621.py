# link: https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
      task_map = [0] * 26
      for task in tasks:
        task_map[ord(task) - ord('A')] += 1
      task_map.sort()
      max_val = task_map[25] - 1
      idle_slots = max_val * n
      for i in range(24, -1, -1):
        idle_slots -= min(task_map[i], max_val)
      return len(tasks) + max(0, idle_slots)
    
# Time complexity: O(n)
# Space complexity: O(1)