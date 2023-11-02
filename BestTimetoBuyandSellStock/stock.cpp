/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution
{
public:
  /**
   * The function calculates the maximum profit that can be made by buying and selling a stock at
   * different prices.
   * 
   * @param prices a vector of integers representing the prices of a stock over a period of time. The
   * function calculates the maximum profit that can be made by buying and selling the stock at
   * different prices during this period.
   * 
   * @return the maximum profit that can be made by buying and selling a stock at different prices in
   * the given vector of prices.
   */
  int maxProfit(vector<int> &prices)
  {
    int minPrice = numeric_limits<int>::max();
    int maxProfit = 0;
    for (int price : prices)
    {
      if (price < minPrice)
      {
        minPrice = price;
      }
      else
      {
        maxProfit = max(maxProfit, price - minPrice);
      }
    }
    return maxProfit;
  }
};

/*
- Time complexity: O(n)
- Space complexity: O(1)
===========================
** Problem explanation and problem solving method **
- Problem explanation:
+ Given an array for which the ith element is the price of a given stock on day i.
+ If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
+ Note that you cannot sell a stock before you buy one.
- Problem solving method:
+ We can use the greedy algorithm to solve this problem.
+ We will keep track of the minimum price and the maximum profit.
+ We will iterate through the array and update the minimum price and the maximum profit.
+ The maximum profit will be the answer.
===========================
*/