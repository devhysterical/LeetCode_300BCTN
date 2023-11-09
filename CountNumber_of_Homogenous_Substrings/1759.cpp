/*
https://leetcode.com/problems/count-number-of-homogenous-substrings/description/?envType=daily-question&envId=2023-11-09
*/
class Solution
{
public:
  int countHomogenous(string s)
  {
    const int MOD = 1e9 + 7;
    long long count = 0;
    int currLength = 1;

    for (int i = 1; i < s.length(); i++)
    {
      if (s[i] == s[i - 1])
      {
        currLength++;
      }
      else
      {
        count = (count + (1LL * currLength * (currLength + 1) / 2) % MOD) % MOD;
        currLength = 1;
      }
    }
    count = (count + (1LL * currLength * (currLength + 1) / 2) % MOD) % MOD;
    
    return static_cast<int>(count);
  }
};
