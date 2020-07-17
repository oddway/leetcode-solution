/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (50.06%)
 * Likes:    5213
 * Dislikes: 228
 * Total Accepted:    883.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 *
 * Example 2:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 */
#include <climits>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        for (size_t i = prices.size() - 1; i > 0; i--) {
            prices[i] = prices[i] - prices[i - 1];
        }

        prices[0] = 0;

        return maxProfitRecursion(prices, 0, prices.size() - 1);
    }

    int maxProfitRecursion(vector<int>& prices, int l, int r) {
        if (l == r) {
            return prices[l];
        }

        int leftMax, rightMax, midMax;

        leftMax = rightMax = midMax = INT_MIN;

        int m = (l + r) / 2;

        leftMax = maxProfitRecursion(prices, l, m);
        rightMax = maxProfitRecursion(prices, m + 1, r);
        midMax = maxProfitCrossing(prices, l, r, m);

        if (leftMax < rightMax) {
            leftMax = rightMax;
        }

        if (leftMax < midMax) {
            leftMax = midMax;
        }

        return leftMax;
    }

    int maxProfitCrossing(vector<int>& prices, int l, int r, int m) {
        int maxLeftProfit = INT_MIN;
        int sum = 0;

        for (int i = m; i >= l; i--) {
            sum += prices[i];
            if (sum > maxLeftProfit) {
                maxLeftProfit = sum;
            }
        }

        int maxRightProfit = INT_MIN;
        sum = 0;

        for (int i = m + 1; i <= r; i++) {
            sum += prices[i];
            if (sum > maxRightProfit) {
                maxRightProfit = sum;
            }
        }

        return maxLeftProfit + maxRightProfit;
    }
};
// @lc code=end
