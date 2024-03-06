# link: https://leetcode.com/problems/binary-watch/description/
class Solution:
    def readBinaryWatch(self, turnOn: int) -> list:
        """
        Generate a list of binary watch times based on the given number of turned-on LEDs.

        Args:
        - turnOn (int): The number of LEDs turned on in the binary watch.

        Returns:
        - list: A list of strings representing valid times in the format "HH:MM".
          The times are generated based on the number of LEDs turned on in the binary watch.
        """
        res = []
        for i in range(12):
            for j in range(60):
                # Count the total number of '1's in the binary representation of hours and minutes
                if (bin(i) + bin(j)).count("1") == turnOn:
                    res.append(f"{i}:{j:02d}")
        return res


# Time complexity: O(1)
# Space complexity: O(1)
