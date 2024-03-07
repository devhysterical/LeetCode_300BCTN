# link: https://leetcode.com/problems/longest-palindrome/description/


class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter

        count = Counter(s)
        ans = 0
        for v in count.values():
            ans += v // 2 * 2
            if ans % 2 == 0 and v % 2 == 1:
                ans += 1
        return ans

# Time complexity: O(n)
# Space complexity: O(1)