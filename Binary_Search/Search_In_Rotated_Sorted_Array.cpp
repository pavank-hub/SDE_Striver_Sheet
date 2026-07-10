/*
LeetCode 33 - Search in Rotated Sorted Array

Approach:
- Use Binary Search on the rotated sorted array.
- For every mid:
    - If nums[mid] is the target, return its index.
    - Determine which half is sorted.
- If the left half is sorted:
    - Check whether the target lies within that range.
    - If yes, search left; otherwise, search right.
- If the right half is sorted:
    - Check whether the target lies within that range.
    - If yes, search right; otherwise, search left.
- Repeat until the target is found or the search space becomes empty.

Time Complexity:
- O(log n) : Binary search halves the search space every iteration
- Overall: O(log n)

Space Complexity:
- O(1) : Only variables are used
- Overall: O(1)

Revision Keywords:
- Binary Search
- Rotated Sorted Array
- Sorted Half
- Pivot Logic
- Search Space Reduction
- Array Medium
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
                return mid;

            // Left half is sorted
            else if(nums[low] <= nums[mid]) {

                if(nums[low] <= target &&
                   target <= nums[mid])

                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half is sorted
            else {

                if(nums[mid] <= target &&
                   target <= nums[high])

                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};
