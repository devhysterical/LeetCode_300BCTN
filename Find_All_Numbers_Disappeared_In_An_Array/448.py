# link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for num in nums:
            index = abs(num) - 1
            if nums[index] > 0:
                nums[index] *= -1
        return [i + 1 for i, num in enumerate(nums) if num > 0]
