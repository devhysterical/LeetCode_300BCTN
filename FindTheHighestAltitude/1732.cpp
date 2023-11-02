// https://leetcode.com/problems/find-the-highest-altitude/

class Solution
{
public:
  int largestAltitude(std::vector<int> &gain)
  {
    int altitude = 0;
    int highestAltitude = 0;
    for (int i = 0; i < gain.size(); i++)
    {
      altitude += gain[i];
      highestAltitude = std::max(highestAltitude, altitude);
    }
    return highestAltitude;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
*/