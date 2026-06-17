/*
LeetCode 287 - Find the Duplicate Number

Approach:
- Use Floyd's Cycle Detection (Tortoise and Hare) algorithm.
- Treat the array as a linked list where:
    - index = current node
    - nums[index] = next node
- Since one number is duplicated, a cycle will be formed.
- First, find the intersection point of slow and fast pointers.
- Then, reset one pointer to the starting position.
- Move both pointers one step at a time until they meet again.
- The meeting point is the duplicate number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);

        // Find entrance of cycle
        fast = nums[0];

        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
