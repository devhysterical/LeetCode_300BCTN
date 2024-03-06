# link: https://leetcode.com/problems/is-subsequence/
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        """
        Check if string 's' is a subsequence of string 't'.

        Given two strings 's' and 't', this function checks whether 's' is a subsequence of 't'.
        A subsequence is a new string formed from the original string by deleting some (or none)
        of the characters without changing the relative order of the remaining characters.

        Args:
        - s (str): The potential subsequence string.
        - t (str): The target string.

        Returns:
        - bool: True if 's' is a subsequence of 't', False otherwise.
        """
        i, j = 0, 0

        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1

        return i == len(s)


# Time complexity: O(n)
# Space complexity: O(1)
