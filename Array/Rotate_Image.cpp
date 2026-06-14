/*
LeetCode 48 - Rotate Image

Approach:
- Rotate the matrix by 90 degrees clockwise in-place.
- First, transpose the matrix:
    - Convert rows into columns by swapping matrix[i][j]
      with matrix[j][i] for all j > i.
- Then, reverse each row of the transposed matrix.
- The combination of transpose + row reversal results in
  a 90-degree clockwise rotation.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
