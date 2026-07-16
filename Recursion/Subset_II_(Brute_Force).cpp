/*
LeetCode 90 - Subsets II

Approach:
- Generate all possible subsets using Recursion + Backtracking.
- For each element:
    - Include it in the current subset.
    - Exclude it from the current subset.
- Since duplicate elements may produce identical subsets:
    - Store each generated subset in a set.
- The set automatically removes duplicate subsets.
- Convert the set into a vector and return the result.

Time Complexity:
- O(2^n) : Total subsets generated
- O(n)   : Insertion/comparison cost for each subset in set
- Overall: O(2^n × n)

Space Complexity:
- O(2^n × n) : Set stores all unique subsets
- O(n)       : Recursion stack depth
- Overall: O(2^n × n)

Revision Keywords:
- Recursion
- Backtracking
- Power Set
- Duplicate Subsets
- Set Deduplication
- Include Exclude Pattern
*/

class Solution {
public:

    set<vector<int>> st;

    void generate(vector<int>& nums,
                  int idx,
                  vector<int>& curr) {

        if(idx == nums.size()) {
            st.insert(curr);
            return;
        }

        // Include nums[idx]
        curr.push_back(nums[idx]);
        generate(nums, idx + 1, curr);

        // Backtrack
        curr.pop_back();

        // Exclude nums[idx]
        generate(nums, idx + 1, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> curr;

        sort(nums.begin(), nums.end());

        generate(nums, 0, curr);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};
