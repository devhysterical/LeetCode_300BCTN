# link: https://leetcode.com/problems/teemo-attacking/description/


class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries:
            return 0
        total = 0
        for i in range(1, len(timeSeries)):
            total += min(timeSeries[i] - timeSeries[i - 1], duration)
        return total + duration


# Time complexity: O(n)
# Space complexity: O(1)
