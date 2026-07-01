/*
LeetCode 876 - Middle of the Linked List

Approach:
- Use the Fast and Slow Pointer technique.
- Initialize both pointers at the head.
- Move:
    - slow by 1 step
    - fast by 2 steps
- When fast reaches the end of the list,
  slow will be at the middle node.
- For even-length lists, the problem requires
  returning the second middle node, which is
  naturally achieved by this approach.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if(!head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
