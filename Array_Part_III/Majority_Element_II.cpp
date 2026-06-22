/*
LeetCode 229 - Majority Element II

Approach:
- Use the Boyer-Moore Voting Algorithm extension.
- Since an element must appear more than n/3 times,
  there can be at most two majority elements.
- Maintain two candidate elements (ele1, ele2) and their counts.
- Traverse the array:
    - If a count becomes 0, assign a new candidate.
    - If the current element matches a candidate, increment its count.
    - Otherwise, decrement both counts.
- Perform a second pass to verify the frequencies of both candidates.
- Add candidates whose frequency is greater than n/3 to the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int cnt1 = 0;
        int cnt2 = 0;

        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        // Find potential candidates
        for(int i = 0; i < n; i++) {

            if(cnt1 == 0 && nums[i] != ele2) {
                cnt1++;
                ele1 = nums[i];
            }

            else if(cnt2 == 0 && nums[i] != ele1) {
                cnt2++;
                ele2 = nums[i];
            }

            else if(nums[i] == ele1)
                cnt1++;

            else if(nums[i] == ele2)
                cnt2++;

            else {
                cnt1--;
                cnt2--;
            }
        }

        // Verify frequencies
        cnt1 = 0;
        cnt2 = 0;

        for(int x : nums) {

            if(x == ele1)
                cnt1++;

            else if(x == ele2)
                cnt2++;
        }

        vector<int> ans;

        if(cnt1 > n / 3)
            ans.push_back(ele1);

        if(cnt2 > n / 3)
            ans.push_back(ele2);

        sort(ans.begin(), ans.end());

        return ans;
    }
};
