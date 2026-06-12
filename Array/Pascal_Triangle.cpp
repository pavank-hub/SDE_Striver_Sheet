/*
LeetCode 118 - Pascal's Triangle

Approach:
- Generate the triangle row by row.
- Each row contains (row + 1) elements.
- The first and last elements of every row are always 1.
- For the remaining elements:
    temp[col] = ans[row - 1][col - 1] + ans[row - 1][col]
- Store each generated row in the answer vector.

Time Complexity: O(numRows²)
Space Complexity: O(numRows²)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;

        if(n == 1)
            return {{1}};

        vector<vector<int>> ans;

        for(int row = 0; row < n; row++) {

            int m = row + 1;
            vector<int> temp(m);

            for(int col = 0; col < m; col++) {

                if(col == 0 || col == (m - 1))
                    temp[col] = 1;
                else
                    temp[col] = ans[row - 1][col] + ans[row - 1][col - 1];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
