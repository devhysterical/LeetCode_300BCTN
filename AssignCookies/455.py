# link: https://leetcode.com/problems/assign-cookies/description/


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        """
        Find the maximum number of content children given a list of greed factors and cookie sizes.

        Given two lists 'g' and 's', where 'g[i]' represents the greed factor of the ith child
        and 's[j]' represents the size of the jth cookie, this function calculates and returns
        the maximum number of content children that can be satisfied.

        The function sorts both lists and iterates through the cookie sizes, assigning them to
        the greediest child if the cookie size is sufficient. It returns the count of content children.

        Args:
        - g (List[int]): The list of greed factors representing children.
        - s (List[int]): The list of cookie sizes.

        Returns:
        - int: The maximum number of content children.
        """
        g.sort()
        s.sort()
        i = 0

        for j in range(len(s)):
            if i < len(g) and s[j] >= g[i]:
                i += 1

        return i


# Time complexity: O(nlogn)
# Space complexity: O(1)
