# link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        """
        Find the disappeared numbers in a range [1, n] from the given list.

        Given a list of integers 'nums' where 1 ≤ nums[i] ≤ len(nums), this function identifies
        and returns the numbers in the range [1, n] that are missing from the list.

        Args:
        - nums (List[int]): The input list of integers.

        Returns:
        - List[int]: A list of integers representing the disappeared numbers in the range [1, n].
        """
        for num in nums:
            index = abs(num) - 1
            if nums[index] > 0:
                nums[index] *= -1

        # Create a list of indices corresponding to positive values
        disappeared_numbers = [i + 1 for i, num in enumerate(nums) if num > 0]

        return disappeared_numbers
# Time complexity: O(n)
# Space complexity: O(1)