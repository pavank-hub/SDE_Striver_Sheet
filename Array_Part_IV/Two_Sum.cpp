/*
LeetCode 1 - Two Sum

Approach:
- Use a hash map to store previously seen numbers and their indices.
- For each element, calculate its complement:
      val = target - nums[i]
- Check if the complement already exists in the hash map.
- If it exists, we have found the pair of indices.
- Otherwise, store the current element and its index in the hash map.
- This is a one-pass hash map solution.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        int n = nums.size();

        int ind1 = 0, ind2 = 1;

        for(int i = 0; i < n; i++) {

            int val = target - nums[i];

            if(mp.find(val) != mp.end() && mp[val] != i) {

                ind1 = i;
                ind2 = mp[val];

                break;
            }

            mp[nums[i]] = i;
        }

        return {ind1, ind2};
    }
};
