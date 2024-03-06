# link: https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution:
    def firstUniqChar(self, s: str) -> int:
        """
        Find the index of the first non-repeating character in a given string.

        Given a string 's', this function calculates the index of the first non-repeating character.
        If all characters are repeated, it returns -1.

        Args:
        - s (str): The input string.

        Returns:
        - int: The index of the first non-repeating character in 's', or -1 if no such character is found.
        """
        char_count = {}
        # Count the occurrences of each character in the string
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        # Iterate through the string to find the first non-repeating character
        for i, char in enumerate(s):
            if char_count[char] == 1:
                return i

        # Return -1 if no non-repeating character is found
        return -1


# Time complexity: O(n)
# Space complexity: O(1) because the size of the dictionary is at most 26
