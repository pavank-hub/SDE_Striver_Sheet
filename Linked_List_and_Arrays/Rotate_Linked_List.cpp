/*
LeetCode 61 - Rotate List

Approach:
- Find the length of the linked list and the tail node.
- Reduce unnecessary rotations using:
      k = k % size
- If k becomes 0, return the original list.
- Connect the tail to the head to form a circular linked list.
- Find the new tail at position:
      size - k - 1
- The node after the new tail becomes the new head.
- Break the circular link and return the new head.

Time Complexity:
- O(n) : Calculate size and reach tail
- O(n) : Find the new tail position
- Overall: O(n)

Space Complexity:
- O(1) : Only pointer manipulation is used
- Overall: O(1)

Revision Keywords:
- Rotate Linked List
- Circular Linked List
- Modulo Optimization
- New Head
- New Tail
- Pointer Manipulation
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || !k)
            return head;

        ListNode* tail = head;

        int size = 1;

        while(tail->next) {
            tail = tail->next;
            size++;
        }

        k %= size;

        if(!k)
            return head;

        // Make list circular
        tail->next = head;

        int move = size - k - 1;

        tail = head;

        while(move--)
            tail = tail->next;

        ListNode* curr = tail->next;

        // Break the circle
        tail->next = NULL;

        return curr;
    }
};
