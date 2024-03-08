# link: https://leetcode.com/problems/hamming-distance/description/


class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        """
        Calculate the Hamming distance between two integers.

        Given two integers 'x' and 'y', this function calculates the Hamming distance,
        which is the number of differing bits when the binary representations of 'x' and 'y'
        are XORed.

        Args:
        - x (int): The first integer.
        - y (int): The second integer.

        Returns:
        - int: The Hamming distance between 'x' and 'y'.
        """
        return bin(x ^ y).count("1")


# Time complexity: O(1)
# Space complexity: O(1)
