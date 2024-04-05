/**
 * @file 506.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-05
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/relative-ranks/description/
 * Time complexity = O(nlogn)
 * Space complexity = O(n)
 */

class Solution
{
public:
  vector<string> findRelativeRanks(vector<int> &score)
  {
    vector<int> temp = score;
    sort(temp.begin(), temp.end(), greater<int>());
    unordered_map<int, string> mp;
    for (int i = 0; i < temp.size(); i++)
    {
      if (i == 0)
        mp[temp[i]] = "Gold Medal";
      else if (i == 1)
        mp[temp[i]] = "Silver Medal";
      else if (i == 2)
        mp[temp[i]] = "Bronze Medal";
      else
        mp[temp[i]] = to_string(i + 1);
    }
    vector<string> res;
    for (int i = 0; i < score.size(); i++)
    {
      res.push_back(mp[score[i]]);
    }
    return res;
  }
};