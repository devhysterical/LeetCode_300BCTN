# link: https://leetcode.com/problems/island-perimeter/description/


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        """
        Calculate the perimeter of an island represented by a 2D grid.

        Given a 2D grid representing an island where 1 represents land and 0 represents water,
        this function calculates and returns the perimeter of the island.

        The island perimeter is calculated by adding 4 units for each land cell and subtracting
        2 units for each adjacent land cell (considering both horizontally and vertically).

        Args:
        - grid (List[List[int]]): The 2D grid representing the island.

        Returns:
        - int: The perimeter of the island.
        """
        perimeter = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    perimeter += 4
                    if i > 0 and grid[i - 1][j] == 1:
                        perimeter -= 2
                    if j > 0 and grid[i][j - 1] == 1:
                        perimeter -= 2

        return perimeter


# Time complexity: O(n)
# Space complexity: O(1)
