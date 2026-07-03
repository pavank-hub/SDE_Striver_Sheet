/*
LeetCode 160 - Intersection of Two Linked Lists

Approach:
- Use the Two Pointer technique.
- Initialize one pointer at headA and another at headB.
- Traverse both lists simultaneously.
- When a pointer reaches the end of its list, redirect it to
  the head of the other list.
- This equalizes the distance traveled by both pointers:
      lengthA + lengthB
- If an intersection exists, both pointers will meet at the
  intersection node.
- If there is no intersection, both pointers will eventually
  become NULL.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b) {

            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};
