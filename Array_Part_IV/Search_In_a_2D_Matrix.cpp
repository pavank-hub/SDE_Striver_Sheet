/*
LeetCode 74 - Search a 2D Matrix

Approach:
- Treat the 2D matrix as a single sorted 1D array.
- Apply Binary Search on indices from 0 to (m * n - 1).
- Convert the 1D index back to 2D coordinates:
    row = mid / n
    col = mid % n
- Compare matrix[row][col] with the target and adjust
  the search space accordingly.
- This avoids performing two separate binary searches.

Time Complexity: O(log(m * n))
Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target)
                return true;

            else if(matrix[row][col] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};
