# link: https://leetcode.com/problems/third-maximum-number/description/
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = list(set(nums))
        if len(nums) < 3:
            return max(nums)
        nums.remove(max(nums))
        nums.remove(max(nums))
        return max(nums)


# Time complexity: O(n)
# Space complexity: O(1)
