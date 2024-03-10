# link: https://leetcode.com/problems/construct-the-rectangle/description/


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        for i in range(int(area**0.5), 0, -1):
            if area % i == 0:
                return [area // i, i]
        return [area, 1]


# Time complexity: O(sqrt(n))
# Space complexity: O(1)
