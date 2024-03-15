# link: https://leetcode.com/problems/keyboard-row/description/


class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        rows = [set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")]
        ans = []
        for word in words:
            for row in rows:
                if all(c.lower() in row for c in word):
                    ans.append(word)
                    break
        return ans

# Time complexity: O(n * m)
# Space complexity: O(1)