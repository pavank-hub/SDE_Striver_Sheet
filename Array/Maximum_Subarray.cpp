/*
LeetCode 53 - Maximum Subarray

Approach:
- Use Kadane's Algorithm.
- Maintain a running sum (curSum) while traversing the array.
- Update maxSum whenever a larger subarray sum is found.
- If curSum becomes negative, reset it to 0 since a negative sum
  will only decrease the sum of any future subarray.
- maxSum is initialized with nums[0] to correctly handle cases
  where all elements are negative.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int maxSum = nums[0];
        int curSum = 0;

        for(int i = 0; i < n; i++) {

            curSum += nums[i];

            maxSum = max(maxSum, curSum);

            if(curSum < 0)
                curSum = 0;
        }

        return maxSum;
    }
};
