/*
GeeksforGeeks - Median in a Row-wise Sorted Matrix

Approach:
- The matrix rows are individually sorted, but the entire matrix
  is not globally sorted.
- Apply Binary Search on the answer (value range), not on indices.
- Search space:
    - low  = minimum first element among all rows
    - high = maximum last element among all rows
- For each mid:
    - Count how many elements are <= mid using upper_bound()
      in every row.
- If count <= required position:
    - Median lies on the right side.
- Otherwise:
    - Median lies on the left side (including mid).
- The first value having more than req elements before it
  is the median.

Time Complexity:
- O(log(maxElement - minElement)) : Binary search on value range
- O(r × log(c)) : Counting elements <= mid using upper_bound for each row
- Overall: O(r × log(c) × log(maxElement - minElement))

Space Complexity:
- O(1) : No extra data structures used
- Overall: O(1)

Revision Keywords:
- Binary Search on Answer
- Median in Matrix
- Row-wise Sorted Matrix
- Upper Bound
- Count <= Mid
- Value Range Search
*/

class Solution {
public:
    int median(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i = 0; i < r; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][c - 1]);
        }

        int req = (r * c) / 2;

        while(low < high) {

            int mid = low + (high - low) / 2;

            int count = 0;

            // Count elements <= mid
            for(int i = 0; i < r; i++) {
                count += upper_bound(
                            mat[i].begin(),
                            mat[i].end(),
                            mid
                         ) - mat[i].begin();
            }

            if(count <= req)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
