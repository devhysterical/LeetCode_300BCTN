# link: https://leetcode.com/problems/repeated-substring-pattern/description/


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        """
        Check if a string can be formed by repeating a substring.

        Given a string 's', this function checks whether it can be formed by repeating
        a substring. It returns True if 's' can be formed this way, and False otherwise.

        Args:
        - s (str): The input string.

        Returns:
        - bool: True if 's' can be formed by repeating a substring, False otherwise.
        """
        return s in (s + s)[1:-1]


# Time complexity: O(n)
# Space complexity: O(n)
