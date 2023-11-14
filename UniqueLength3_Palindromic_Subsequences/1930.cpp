/*
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2023-11-14

- Time Complexity: O(n)
- Space Complexity: O(1)
*/
class Solution
{
public:
  int countPalindromicSubsequence(string s)
  {
    int n = s.size();
    vector<int> first(26, n), last(26, -1);
    for (int i = 0; i < n; ++i)
    {
      first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
      last[s[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
    {
      if (first[i] < last[i])
      {
        vector<bool> inBetween(26);
        for (int j = first[i] + 1; j < last[i]; ++j)
        {
          inBetween[s[j] - 'a'] = true;
        }
        ans += count(inBetween.begin(), inBetween.end(), true);
      }
    }
    return ans;
  }
};
