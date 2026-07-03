/*
LeetCode 141 - Linked List Cycle

Approach:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).
- Maintain two pointers:
    - slow moves one step at a time.
    - fast moves two steps at a time.
- If a cycle exists, the fast pointer will eventually
  meet the slow pointer inside the cycle.
- If fast reaches NULL, no cycle exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};
