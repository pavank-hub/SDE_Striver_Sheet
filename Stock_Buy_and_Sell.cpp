/*
LeetCode 121 - Best Time to Buy and Sell Stock

Approach:
- Traverse the array while maintaining the minimum stock price
  encountered so far.
- For each day, calculate the profit that would be obtained by
  selling the stock on the next day after buying at the minimum
  price seen so far.
- Update the maximum profit whenever a larger profit is found.
- This ensures that buying always happens before selling.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int maxSum = 0;
        int minPrice = prices[0];

        for(int i = 0; i < n - 1; i++) {

            minPrice = min(minPrice, prices[i]);

            maxSum = max(maxSum, prices[i + 1] - minPrice);
        }

        return maxSum;
    }
};
