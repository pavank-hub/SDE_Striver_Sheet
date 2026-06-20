/*
LeetCode 169 - Majority Element

Approach:
- Use the Boyer-Moore Voting Algorithm.
- Maintain a candidate element (ele) and a counter (count).
- If count becomes 0, choose the current element as the new candidate.
- If the current element matches the candidate, increment count.
- Otherwise, decrement count.
- Since the problem guarantees the existence of a majority element
  (frequency > n/2), the final candidate is the answer.
- If the majority element was not guaranteed, a second pass would
  be required to verify its frequency.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int ele = 0;
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(count == 0)
                ele = nums[i];

            if(nums[i] == ele)
                count++;
            else
                count--;
        }

        // If majority element was not guaranteed,
        // verify using a second pass.

        return ele;
    }
};
