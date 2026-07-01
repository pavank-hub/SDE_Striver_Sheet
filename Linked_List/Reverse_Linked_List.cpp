/*
LeetCode 206 - Reverse Linked List

Approach:
- Use three pointers:
    - prev : points to the previous node
    - curr : points to the current node
    - fut  : stores the next node
- Traverse the linked list and reverse the direction of each link.
- Move all pointers one step forward after each reversal.
- At the end, prev points to the new head of the reversed list.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *prev, *curr, *fut;

        prev = NULL;
        curr = head;

        while(curr) {

            fut = curr->next;

            curr->next = prev;

            prev = curr;
            curr = fut;
        }

        return prev;
    }
};
