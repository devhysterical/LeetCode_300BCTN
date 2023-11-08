/*
https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/?envType=daily-question&envId=2023-11-08
*/
class Solution
{
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
  {
    if (sx == fx && sy == fy)
    {
      return (t > 1 || t == 0);
    }
    int heightDifference = abs(sy - fy);
    int widthDifference = abs(sx - fx);

    int extraTime = abs(heightDifference - widthDifference);

    return (min(heightDifference, widthDifference) + extraTime) <= t;
  }
};