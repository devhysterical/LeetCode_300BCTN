// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if (needle.empty())
    {
      return 0;
    }
    size_t found = haystack.find(needle);
    if (found != string::npos)
    {
      return static_cast<int>(found);
    }
    return -1;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
*/