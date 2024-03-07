# link: https://leetcode.com/problems/add-strings/description/


class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ""
        carry = 0

        i, j = len(num1) - 1, len(num2) - 1
        while i >= 0 or j >= 0:
            n1 = int(num1[i]) if i >= 0 else 0
            n2 = int(num2[j]) if j >= 0 else 0
            temp = n1 + n2 + carry
            carry = temp // 10
            res = str(temp % 10) + res
            i -= 1
            j -= 1
        return "1" + res if carry else res


# Time complexity: O(n)
# Space complexity: O(1)
