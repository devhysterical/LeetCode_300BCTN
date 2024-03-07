# link: https://leetcode.com/problems/arranging-coins/description/


class Solution:
    def arrangeCoins(self, n: int) -> int:
        """
        Calculate the maximum number of full staircases that can be formed with 'n' coins.

        Given a total number of coins 'n', this function calculates the maximum number of
        full staircases (rows) that can be formed, where each staircase has an increasing
        number of coins in each row.

        Args:
        - n (int): The total number of coins.

        Returns:
        - int: The maximum number of full staircases that can be formed with 'n' coins.
        """
        return int((2 * n + 0.25) ** 0.5 - 0.5)
# Time complexity: O(1)
# Space complexity: O(1)