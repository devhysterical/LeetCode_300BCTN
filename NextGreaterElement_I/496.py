# link: https://leetcode.com/problems/next-greater-element-i/description/


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack, d = [], {}
        for n in nums2:
            while stack and stack[-1] < n:
                d[stack.pop()] = n
            stack.append(n)
        return [d.get(n, -1) for n in nums1]


# Time complexity: O(n)
# Space complexity: O(n)
