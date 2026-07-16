/*
LeetCode 90 - Subsets II

Approach:
- Sort the array so that duplicate elements become adjacent.
- Use Backtracking to generate subsets.
- At each recursive call:
    - Add the current subset to the answer.
    - Iterate through the remaining elements.
- To avoid duplicate subsets:
    - Skip an element if it is the same as the previous element
      at the same recursion level.
      Condition:
          if(i > idx && nums[i] == nums[i - 1]) continue;
- This generates only unique subsets without using a set.

Time Complexity:
- O(2^n) : Total unique subsets generated
- O(n)   : Copying subset into answer in the worst case
- Overall: O(2^n × n)

Space Complexity:
- O(n) : Recursion stack depth
- O(n) : Current subset storage
- Overall: O(n)
  (excluding output array)

Revision Keywords:
- Backtracking
- Subsets II
- Duplicate Skipping
- Recursion Tree
- Sort First
- Power Set
- Include Choice
*/

class Solution {
public:

    vector<vector<int>> ans;

    void generate(vector<int>& nums,
                  vector<int>& curr,
                  int idx) {

        ans.push_back(curr);

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if(i > idx &&
               nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);

            generate(nums, curr, i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> curr;

        sort(nums.begin(), nums.end());

        generate(nums, curr, 0);

        return ans;
    }
};
