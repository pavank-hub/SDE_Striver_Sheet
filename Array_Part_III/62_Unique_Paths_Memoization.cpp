/*
LeetCode 62 - Unique Paths

Approach:
- Use Recursion + Memoization (Top-Down DP).
- Start from (0,0) and recursively explore:
    - Move Down: (row + 1, col)
    - Move Right: (row, col + 1)
- If we go out of bounds, return 0.
- If we reach the destination (m-1, n-1), return 1.
- Use a DP table to store previously computed states and
  avoid recalculating overlapping subproblems.
- Each state dp[row][col] represents the number of unique
  paths from that cell to the destination.

Time Complexity: O(m * n)
Space Complexity: O(m * n) + O(m + n)
( DP table + recursion stack )
*/

class Solution {
public:

    // Recursion + Memoization
    int diffPath(int row, int col, int m, int n,
                 vector<vector<int>>& dp) {

        if(row == m || col == n)
            return 0;

        if(row == m - 1 && col == n - 1)
            return 1;

        if(dp[row][col] != INT_MIN)
            return dp[row][col];

        return dp[row][col] =
            diffPath(row + 1, col, m, n, dp) +
            diffPath(row, col + 1, m, n, dp);
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(
            m, vector<int>(n, INT_MIN)
        );

        return diffPath(0, 0, m, n, dp);
    }
};
