/*
LeetCode 56 - Merge Intervals

Approach:
- Sort the intervals based on their starting times.
- Traverse each interval one by one.
- If the answer vector is empty or the current interval does not
  overlap with the last interval in the answer, add it directly.
- Otherwise, merge the overlapping intervals by updating the end
  value with the maximum ending point.
- Continue until all intervals are processed.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Non-overlapping interval
            if(ans.empty() || ans.back()[1] < start)
                ans.push_back(intervals[i]);

            // Overlapping interval
            else
                ans.back()[1] = max(ans.back()[1], end);
        }

        return ans;
    }
};
