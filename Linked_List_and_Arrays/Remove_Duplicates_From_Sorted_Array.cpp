/*
LeetCode 26 - Remove Duplicates from Sorted Array

Approach:
- Use the Two Pointer technique.
- Pointer i tracks the position of the last unique element.
- Pointer j scans the array for new unique elements.
- Whenever nums[j] differs from nums[i]:
    - Move i forward.
    - Place nums[j] at index i.
- After traversal, the first (i + 1) elements contain all unique values.
- Return the count of unique elements.

Time Complexity:
- O(n) : Single traversal of the array using pointer j
- O(1) : Work done per iteration
- Overall: O(n)

Space Complexity:
- O(1) : In-place modification of the array
- Overall: O(1)

Revision Keywords:
- Two Pointers
- Sorted Array
- In-Place Modification
- Unique Elements
- Slow & Fast Pointer
- Array Easy
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return n;

        int count = 1;

        int i = 0;
        int j = i + 1;

        while(j < n) {

            if(nums[i] != nums[j]) {

                i++;
                count++;

                nums[i] = nums[j];
            }

            j++;
        }

        return count;
    }
};
