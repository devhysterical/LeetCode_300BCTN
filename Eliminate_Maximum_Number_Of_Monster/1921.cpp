/*
https://leetcode.com/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-11-07
*/

public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<double> time(dist.size());
    for (int i = 0; i < dist.size(); i++) {
      time[i] = (double)dist[i] / speed[i];
    }
    sort(time.begin(), time.end());
    for (int i = 0; i < time.size(); i++) {
      if (time[i] <= i) {
        return i;
      }
    }
    return time.size();
  }
};