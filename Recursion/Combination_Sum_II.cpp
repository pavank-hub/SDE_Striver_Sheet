/*
LeetCode 40 - Combination Sum II

Approach:
- Sort the array to bring duplicate elements together.
- Use Backtracking to generate combinations.
- Iterate from the current index and choose an element.
- Each element can be used only once:
    - Move to i + 1 after choosing nums[i].
- Skip duplicates at the same recursion level:
      if(i > idx && nums[i] == nums[i - 1]) continue;
- Since the array is sorted:
    - If nums[i] > target, break immediately.
    - No further element can contribute to a valid combination.
- Backtrack after every recursive call.

Time Complexity:
- O(2^n) : Explore all possible subsets/combinations
- O(k)   : Copying a valid combination into answer
- Overall: O(2^n × k)

Where:
- n = Number of candidates
- k = Average length of a valid combination

Space Complexity:
- O(n) : Maximum recursion depth
- O(k) : Current combination storage
- Overall: O(n)

(excluding output storage)

Revision Keywords:
- Backtracking
- Combination Sum II
- Single Usage
- Duplicate Skipping
- Sort First
- Pruning
- For Loop Recursion
*/

class Solution {
public:

    vector<vector<int>> ans;

    void generate(vector<int>& nums,
                  vector<int>& curr,
                  int t,
                  int idx) {

        if(t == 0) {
            ans.push_back(curr);
            return;
        }

        if(t < 0 || idx == nums.size())
            return;

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicates at same level
            if(i > idx &&
               nums[i] == nums[i - 1])
                continue;

            // Pruning
            if(nums[i] > t)
                break;

            curr.push_back(nums[i]);

            generate(nums,
                     curr,
                     t - nums[i],
                     i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        vector<int> curr;

        sort(candidates.begin(),
             candidates.end());

        generate(candidates,
                 curr,
                 target,
                 0);

        return ans;
    }
};
