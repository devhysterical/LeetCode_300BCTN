# https://leetcode.com/problems/license-key-formatting/


class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        """
        Format a license key string by inserting hyphens every 'k' characters.

        Given a license key string 's' containing alphanumeric characters and hyphens,
        this function removes hyphens, converts all characters to uppercase, and inserts
        hyphens every 'k' characters in the resulting string.

        Args:
        - s (str): The input license key string.
        - k (int): The number of characters between hyphens in the formatted string.

        Returns:
        - str: The formatted license key string.
        """
        # Remove hyphens and convert to uppercase
        s = s.replace("-", "").upper()

        size = len(s)
        first_group = size % k
        res = s[:first_group]

        # Insert hyphens every 'k' characters
        while first_group < size:
            if first_group:
                res += "-"
            res += s[first_group : first_group + k]
            first_group += k

        return res


# Time complexity: O(n)
# Space complexity: O(n)
