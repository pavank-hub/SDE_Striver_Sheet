/*
LeetCode 39 - Combination Sum

Approach:
- Use Recursion + Backtracking.
- At each index, we have two choices:
    1. Include the current element.
       - Reduce target by nums[idx].
       - Stay at the same index because the element
         can be used unlimited times.
    2. Exclude the current element.
       - Move to the next index.
- If target becomes 0:
    - A valid combination is found.
- If target becomes negative or all elements are exhausted:
    - Stop exploring that path.
- Backtrack after every inclusion to explore other combinations.

Time Complexity:
- O(2^T) : Recursive exploration of combinations
- O(k)   : Copying a valid combination into the answer
- Overall: Exponential

Where:
- T = Target value
- k = Average length of a valid combination

Space Complexity:
- O(T) : Maximum recursion depth in worst case
- O(k) : Current combination storage
- Overall: O(T)

(excluding output storage)

Revision Keywords:
- Backtracking
- Combination Sum
- Pick / Not Pick
- Unlimited Choices
- Target Reduction
- Recursion Tree
*/

class Solution {
public:

    vector<vector<int>> ans;

    void generate(vector<int>& nums,
                  vector<int>& curr,
                  int t,
                  int idx) {

        // Valid combination found
        if(t == 0) {
            ans.push_back(curr);
            return;
        }

        // Invalid state
        if(idx == nums.size() || t < 0)
            return;

        // Include current element
        curr.push_back(nums[idx]);

        generate(nums,
                 curr,
                 t - nums[idx],
                 idx);

        // Backtrack
        curr.pop_back();

        // Exclude current element
        generate(nums,
                 curr,
                 t,
                 idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<int> curr;

        generate(candidates,
                 curr,
                 target,
                 0);

        return ans;
    }
};
