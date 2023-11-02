// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int left = 0;
    int right = letters.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (letters[mid] <= target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return (left < letters.size()) ? letters[left] : letters[0];
  }
};

/*
- Time complexity: O(log n)
- Space complexity: O(1)
*/