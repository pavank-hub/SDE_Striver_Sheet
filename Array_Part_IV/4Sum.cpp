/*
LeetCode 18 - 4Sum

Approach:
- Sort the array to enable efficient duplicate handling and two-pointer traversal.
- Fix the first two elements using nested loops (i, j).
- Use Two Pointers (k, l) to find the remaining two elements such that:
      nums[i] + nums[j] + nums[k] + nums[l] = target
- Skip duplicate values for i, j, k, and l to avoid duplicate quadruplets.
- Use long long while computing the sum to prevent integer overflow.

Time Complexity: O(n³)
Space Complexity: O(1)
(Excluding the space used for the output)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i != 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < n; j++) {

                if(j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while(k < l) {

                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target) {

                        ans.push_back(
                            {nums[i], nums[j], nums[k], nums[l]}
                        );

                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k - 1])
                            k++;

                        while(k < l && nums[l] == nums[l + 1])
                            l--;
                    }

                    else if(sum < target)
                        k++;

                    else
                        l--;
                }
            }
        }

        return ans;
    }
};
