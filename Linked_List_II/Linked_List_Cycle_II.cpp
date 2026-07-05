/*
LeetCode 142 - Linked List Cycle II

Approach:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).
- Move:
    - slow pointer by 1 step
    - fast pointer by 2 steps
- If they meet, a cycle exists.
- Reset slow to head while keeping fast at the meeting point.
- Move both pointers one step at a time.
- The node where they meet again is the starting node of the cycle.
- If fast reaches NULL, no cycle exists.

Time Complexity:
- O(n) : Detect cycle using slow and fast pointers
- O(n) : Find cycle entrance after detection
- Overall: O(n)

Space Complexity:
- O(1) : Only pointer variables are used
- Overall: O(1)

Revision Keywords:
- Floyd's Cycle Detection
- Tortoise and Hare
- Fast & Slow Pointer
- Cycle Detection
- Cycle Entrance
- Meeting Point
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                slow = head;

                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};
