/*
LeetCode 15 - 3Sum

Approach:
- Sort the array to efficiently handle duplicates and use Two Pointers.
- Fix one element at index i.
- Use two pointers:
    - j = i + 1
    - k = n - 1
- Find pairs such that:
      nums[i] + nums[j] + nums[k] = 0
- If a triplet is found:
    - Store it in the answer.
    - Move both pointers and skip duplicates.
- Skip duplicate values of i to avoid duplicate triplets.

Time Complexity: O(n²)
Space Complexity: O(1)
(Excluding the space used for the output)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i != 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];

                if(sum == 0) {

                    ans.push_back(
                        {nums[i], nums[j], nums[k]}
                    );

                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1])
                        j++;

                    while(j < k && nums[k] == nums[k + 1])
                        k--;
                }

                else if(sum < 0)
                    j++;

                else
                    k--;
            }
        }

        return ans;
    }
};
