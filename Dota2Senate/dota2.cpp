/*
https://leetcode.com/problems/dota2-senate/
*/

class Solution
{
public:
  /**
   * The function predicts the victory of either the Radiant or Dire team in a game based on the order
   * of their members in a given string.
   * 
   * @param senate a string representing the senate where each character represents a senator belonging
   * to either the Radiant party ('R') or the Dire party ('D'). The function predicts which party will
   * emerge victorious in the end based on a set of rules.
   * 
   * @return a string indicating the party that will win in a senate vote. If the queue of "radiant"
   * senators is empty, it means that all of them have been eliminated, so the function returns "Dire"
   * indicating that the "dire" party has won. Otherwise, if the queue of "dire" senators is empty, it
   * means that all of them have been eliminated, so
   */
  string predictPartyVictory(string senate)
  {
    queue<int> radiant, dire;
    int n = senate.size();
    for (int i = 0; i < n; i++)
    {
      if (senate[i] == 'R')
      {
        radiant.push(i);
      }
      else
      {
        dire.push(i);
      }
    }
    while (!radiant.empty() && !dire.empty())
    {
      int r_index = radiant.front();
      int d_index = dire.front();
      if (r_index < d_index)
      {
        radiant.push(r_index + n);
      }
      else
      {
        dire.push(d_index + n);
      }
      radiant.pop();
      dire.pop();
    }
    return radiant.empty() ? "Dire" : "Radiant";
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(n)
===========================
** Problem explanation and problem solving method **
- Problem explanation:
+ In the game of Dota 2, there are two parties: the Radiant and the Dire.
+ The Dota 2 senate consists of senators coming from two parties.
+ Now the senate wants to make a decision about a change in the Dota 2 game.
+ The voting for this change is a round-based procedure.
+ In each round, each senator can exercise one of the two rights:
  + Ban one senator's right:
    + A senator can make another senator lose all his rights in this and all the following rounds.
  + Announce the victory:
    + If this senator found the senators who still have rights to vote are all from the same party,
      he can announce the victory and make the decision about the change in the game.
+ Given a string senate representing each senator's party belonging.
+ The character 'R' and 'D' represent the Radiant party and the Dire party respectively.
+ Then if there are more senators from the Radiant party than the Dire party, return "Radiant".
+ If there are more senators from the Dire party than the Radiant party, return "Dire".
+ Otherwise, return the party that will eventually win.
- Problem solving method:
+ We can use the greedy algorithm to solve this problem.
+ We will keep track of the number of slots for each size.
+ We will iterate through the array and update the number of slots for each size.
+ The maximum profit will be the answer.
===========================
*/