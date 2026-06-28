/*
LeetCode 1 - Two Sum

Approach:
- Store each element along with its original index in a pair vector.
- Sort the vector based on element values.
- Use the Two Pointer technique:
    - One pointer starts from the beginning.
    - One pointer starts from the end.
- If the current sum equals the target, return the original indices.
- If the sum is greater than the target, move the right pointer left.
- Otherwise, move the left pointer right.
- Sorting changes the order of elements, so original indices are preserved
  in the pair vector.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> arr;

        int n = nums.size();

        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        int i = 0;
        int j = n - 1;

        while(i < j) {

            long long sum = arr[i].first + arr[j].first;

            int t = target;

            if(sum == t)
                return {arr[i].second, arr[j].second};

            else if(sum > t)
                j--;

            else
                i++;
        }

        return {};
    }
};
