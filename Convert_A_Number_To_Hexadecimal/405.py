# link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/


class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
        if num < 0:
            num += 2**32
        hexa = "0123456789abcdef"
        res = ""
        while num:
            res = hexa[num % 16] + res
            num //= 16
        return res


# Time complexity: O(logn)
# Space complexity: O(1)
