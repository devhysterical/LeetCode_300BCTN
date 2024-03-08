# https://leetcode.com/problems/max-consecutive-ones/description/


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        """
        Find the maximum number of consecutive ones in a binary list.

        Given a binary list 'nums', this function calculates and returns the maximum
        number of consecutive ones in the list.

        Args:
        - nums (List[int]): The binary list.

        Returns:
        - int: The maximum number of consecutive ones in the binary list.
        """
        max_ones = 0
        count = 0

        for num in nums:
            if num == 1:
                count += 1
                max_ones = max(max_ones, count)
            else:
                count = 0

        return max_ones


# Time complexity: O(n)
# Space complexity: O(1)
