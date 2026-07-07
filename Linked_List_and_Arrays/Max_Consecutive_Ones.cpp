/*
LeetCode 485 - Max Consecutive Ones

Approach:
- Traverse the array and maintain a count of consecutive 1s.
- If the current element is 1:
    - Increment the current count.
- If the current element is 0:
    - Reset the count to 0.
- Update the maximum count encountered during traversal.
- The maximum count represents the longest streak of consecutive 1s.

Time Complexity:
- O(n) : Single traversal of the array
- O(1) : Work done per iteration
- Overall: O(n)

Space Complexity:
- O(1) : Only variables are used
- Overall: O(1)

Revision Keywords:
- Consecutive Elements
- Running Count
- Array Traversal
- Longest Streak
- Count Reset
- Array Easy
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int longest = 0;
        int count = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(nums[i] == 0)
                count = 0;
            else
                count++;

            longest = max(longest, count);
        }

        return longest;
    }
};
