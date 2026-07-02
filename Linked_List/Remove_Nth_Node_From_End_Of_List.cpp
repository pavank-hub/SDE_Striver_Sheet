/*
LeetCode 19 - Remove Nth Node From End of List

Approach:
- Use the Two Pointer (Fast & Slow) technique.
- Move the fast pointer n steps ahead.
- Then move both fast and slow pointers together until
  fast reaches the end of the list.
- At this point:
    - slow points to the Nth node from the end.
    - prev points to the node just before slow.
- Remove the target node by updating prev->next.
- Handle the special case where the head itself needs
  to be removed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++)
            fast = fast->next;

        // Move both pointers together
        while(fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }

        // Remove head node
        if(!prev)
            return head->next;

        // Remove target node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
