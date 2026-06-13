/*
LeetCode 75 - Sort Colors

Approach:
- Use the Dutch National Flag Algorithm.
- Maintain three pointers:
    low  -> position for next 0
    mid  -> current element being processed
    high -> position for next 2
- If nums[mid] == 0:
    - Swap with nums[low]
    - Increment both low and mid
- If nums[mid] == 1:
    - It is already in the correct region, so increment mid
- If nums[mid] == 2:
    - Swap with nums[high]
    - Decrement high
    - Do not increment mid because the swapped element
      needs to be processed
- Continue until mid crosses high.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
