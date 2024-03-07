# link: https://leetcode.com/problems/number-of-segments-in-a-string/


class Solution:
    def countSegments(self, s: str) -> int:
        """
        Count the number of segments in a string.

        Given a string 's', this function counts and returns the number of segments
        in the string. A segment is defined as a contiguous sequence of non-space characters.

        Args:
        - s (str): The input string.

        Returns:
        - int: The number of segments in the given string.
        """
        return len(s.split())
# Time complexity: O(n)
# Space complexity: O(n)